/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:18:15 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/26 19:00:03 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_end(t_env *e, char *buf_to_del, t_tcpsock *server, const char *msg)
{
	void		*data;

	ft_strdel(&buf_to_del);
	while ((data = ft_queue_pop(&e->actions)))
		ft_memdel(&data);
	while ((data = ft_queue_pop(&e->waits)))
		ft_memdel(&data);
	ft_fatal((char *)msg);
	ftsock_destroy(&server);
}

void	ft_welcome(t_env *e, t_tcpsock *server)
{
	char	*recv;
	char	**split;

	sleep(1);
	ft_putendl_fd(e->team, server->sock);
	if (get_next_line(server->sock, &recv) <= 0)
		ft_end(e, NULL, server, "not enough space.");
	if (ft_strequ(recv, "ko"))
		ft_end(e, recv, server, "bad team");
	e->nb_connect = ft_atoi(recv);
	ft_strdel(&recv);
	get_next_line(server->sock, &recv);
	split = ft_strsplit(recv, ' ');
	e->x = ft_atoi(split[0]);
	e->y = ft_atoi(split[1]);
	ft_split_destroy(split);
}

int		ft_push_go_up(int len, t_env *e)
{
	int		i;

	i = 0;
	while (i < len)
	{
		e->actions = ft_queue_push(e->actions, ft_strdup("avance"));
		i++;
	}
	return (i);
}

int		ft_track_target(int numcase, int line, t_env *e)
{
	int		move_up;
	int		move_side;
	int		counter;

	counter = 0;
	move_up = line + 1;
	move_side = numcase - e->vision[line].center;
	counter += ft_push_go_up(move_up, e);
	if (move_side < 0)
		e->actions = ft_queue_push(e->actions, ft_strdup("gauche"));
	else if (move_side > 0)
		e->actions = ft_queue_push(e->actions, ft_strdup("droite"));
	if (move_side != 0)
		counter++;
	move_side = ft_abs(move_side);
	counter += ft_push_go_up(move_side, e);
	return (counter);
}

int		ft_track(int numcase, t_env *e)
{
	int		i;
	int		start;
	int		end;
	int		line;

	if (numcase == 0)
	{
		e->actions = ft_queue_push(e->actions, ft_strdup("prend nourriture"));
		return (1);
	}
	i = 0;
	line = -1;
	while (i < 8 && line == -1)
	{
		start = e->vision[i].range_start;
		end = e->vision[i].range_end;
		if (numcase >= start && numcase <= end)
			line = i;
		i++;
	}
	if (line != -1)
		return (ft_track_target(numcase, line, e));
	return (0);
}

int		ft_look_for(t_env *e, char **split, t_tcpsock *server, const char *obj)
{
	int		presence;
	int		i;

	presence = 0;
	i = 0;
	while (split[i])
	{
		if (split[i] && *split[i] && ft_strstr(split[i], obj) != NULL)
		{
			presence = 1;
			if (ft_track(i, e))
				FD_SET(server->sock, &e->write_fds);
			break ;
		}
		i++;
	}
	return (presence);
}

void	ft_see(char *recv_buf, t_env *e, t_tcpsock *server)
{
	void	*action;
	char	**split;
	int		presence;

	if (e->waits == NULL)
		ft_fatal("'ok' received, but nothing is in the waitings queue.");
	action = ft_queue_pop(&e->waits);
	recv_buf[ft_strlen(recv_buf) - 1] = 0;
	recv_buf++;
	split = ft_strsplit_strict(recv_buf, ',');
	presence = 0;
	if (e->state == STATE_HUNGRY)
		presence = ft_look_for(e, split, server, "nourriture");
	ft_split_destroy(split);
	ft_memdel(&action);
	if (!presence)
	{
		ft_push_go_up(e->level, e);
		FD_SET(server->sock, &e->write_fds);
	}
}

void	ft_inventory(char *recv_buf, t_env *e)
{
	void	*action;
	char	**split;

	if (e->waits == NULL)
		ft_fatal("'ok' received, but nothing is in the waitings queue.");
	action = ft_queue_pop(&e->waits);
	recv_buf[ft_strlen(recv_buf) - 1] = 0;
	recv_buf++;
	split = ft_strsplit_strict(recv_buf, ',');
	e->inventory.life = ft_atoi(ft_strchr(split[0], ' ') + 1);
	if (e->inventory.life < 8 && e->state != STATE_HUNGRY)
	{
		ft_putendl("STATE : HUNGRY");
		e->state = STATE_HUNGRY;
	}
	else if (e->inventory.life > 30 && e->state != STATE_FARM)
	{
		ft_putendl("STATE : FARM");
		e->state = STATE_FARM;
	}
	ft_split_destroy(split);
	ft_memdel(&action);
}

void	ft_receive_data(char *recv, t_env *e, t_tcpsock *server)
{
	void		*data;

	if (ft_strequ(recv, "BIENVENUE"))
		ft_welcome(e, server);
	else if (ft_strequ(e->waits->data, "voir"))
		ft_see(recv, e, server);
	else if (ft_strequ(e->waits->data, "inventaire"))
		ft_inventory(recv, e);
	else if (ft_strequ(recv, "ok"))
	{
		data = ft_queue_pop(&e->waits);
		ft_memdel(&data);
	}
	else if (ft_strequ(recv, "mort"))
		ft_end(e, recv, server, "I'M DEAD !");
	else
		ft_printf("UNKNOW DATA : %s\nVALUE SENDED : %s\n", recv, ft_queue_pop(&e->waits));
	if (e->actions == NULL && e->waits == NULL)
	{
		e->actions = ft_queue_push(e->actions, ft_strdup("inventaire"));
		e->actions = ft_queue_push(e->actions, ft_strdup("voir"));
		FD_SET(server->sock, &e->write_fds);
	}
	else if (e->actions)
		FD_SET(server->sock, &e->write_fds);
}

void	ft_send_data(t_env *e, t_tcpsock *server)
{
	void	*action;

	if (e->actions)
	{
		action = ft_queue_pop(&e->actions);
		e->waits = ft_queue_push(e->waits, action);
		sleep(1);
		if (ft_strequ(action, "voir"))
			ft_putendl_fd("voir", server->sock);
		else if (ft_strequ(action, "avance"))
			ft_putendl_fd("avance", server->sock);
		else if (ft_strequ(action, "gauche"))
			ft_putendl_fd("gauche", server->sock);
		else if (ft_strequ(action, "droite"))
			ft_putendl_fd("droite", server->sock);
		else if (ft_strequ(action, "inventaire"))
			ft_putendl_fd("inventaire", server->sock);
		else if (ft_strncmp(action, "prend ", 6) == 0)
			ft_putendl_fd(action, server->sock);
	}
	else
		ft_fatal("ERROR : NO ACTIONS TO SEND.");
}

void	ft_main_loop(t_env *e, t_tcpsock *server)
{
	char		*recv_buf;

	FD_ZERO(&e->write_fds);
	FD_ZERO(&e->read_fds);
	while (42)
	{
		FD_SET(server->sock, &e->read_fds);
		select(server->sock + 1, &e->read_fds, &e->write_fds, NULL, NULL);
		if (FD_ISSET(server->sock, &e->read_fds))
		{
			if (get_next_line(server->sock, &recv_buf) <= 0)
				ft_end(e, recv_buf, server, "SERVER CRASHED !");
			ft_printf("RECEIVE : %s\n", recv_buf);
			ft_receive_data(recv_buf, e, server);
			ft_strdel(&recv_buf);
			FD_ZERO(&e->read_fds);
		}
		else if (FD_ISSET(server->sock, &e->write_fds))
		{
			if (ft_queue_len(e->waits) < 9)
			{
				if (e->actions)
					ft_printf("SENDING : %s\n", e->actions->tail->data);
				ft_send_data(e, server);
				if (!e->actions)
					FD_ZERO(&e->write_fds);
			}
		}
	}
}

void	ft_raw_init(t_raw *raw, int range_start, int center, int range_end)
{
	raw->range_start = range_start;
	raw->center = center;
	raw->range_end = range_end;
}

void	ft_vision_init(t_env *e)
{
	ft_raw_init(&e->vision[0], 1, 2, 3);
	ft_raw_init(&e->vision[1], 4, 6, 8);
	ft_raw_init(&e->vision[2], 9, 12, 15);
	ft_raw_init(&e->vision[3], 16, 20, 24);
	ft_raw_init(&e->vision[4], 25, 30, 35);
	ft_raw_init(&e->vision[5], 36, 42, 48);
	ft_raw_init(&e->vision[6], 49, 56, 63);
	ft_raw_init(&e->vision[7], 64, 72, 80);
}

void	ft_inventory_init(t_env *e)
{
	ft_bzero(&e->inventory, sizeof(t_inventory));
	e->inventory.life = 10;
}

void	ft_step_init(t_env *e, int level, const char *format)
{
	char		**split;

	split = ft_strsplit(format, ' ');
	e->steps[level].needed_players = ft_atoi(split[0]);
	e->steps[level].needed_stones.linemate = ft_atoi(split[1]);
	e->steps[level].needed_stones.deraumere = ft_atoi(split[2]);
	e->steps[level].needed_stones.sibure = ft_atoi(split[3]);
	e->steps[level].needed_stones.mendiane = ft_atoi(split[4]);
	e->steps[level].needed_stones.phiras = ft_atoi(split[5]);
	e->steps[level].needed_stones.thystame = ft_atoi(split[6]);
	ft_split_destroy(split);
}

void	ft_steps_init(t_env *e)
{
	ft_step_init(e, 1, "1 1 0 0 0 0 0");
	ft_step_init(e, 2, "2 1 1 1 0 0 0");
	ft_step_init(e, 3, "2 2 0 1 0 2 0");
	ft_step_init(e, 4, "4 1 1 2 0 1 0");
	ft_step_init(e, 5, "4 1 2 1 3 0 0");
	ft_step_init(e, 6, "6 1 2 3 0 1 0");
	ft_step_init(e, 7, "6 2 2 2 2 2 1");
}

int		main(int argc, char **argv)
{
	t_env			e;
	t_tcpsock		*server;

	if (argc != 4)
		ft_fatal("Usage: ./client <ip/dns> <port> <team>");
	e.team = argv[3];
	e.actions = NULL;
	e.waits = NULL;
	e.level = 1;
	ft_inventory_init(&e);
	ft_steps_init(&e);
	e.state = STATE_HUNGRY;
	ft_vision_init(&e);
	server = ftsock_create(FTSOCK_CLIENT, argv[1], ft_atoi(argv[2]));
	ftsock_connect(server);
	if (server->error)
		ftsock_perror(server->error);
	ft_main_loop(&e, server);
	ftsock_destroy(&server);
	return (0);
}
