/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:18:15 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/25 08:42:16 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_welcome(t_env *e, t_tcpsock *server)
{
	char	*recv;
	char	**split;

	ft_putendl_fd(e->team, server->sock);
	get_next_line(server->sock, &recv);
	if (ft_strequ(recv, "ko"))
	{
		ft_strdel(&recv);
		ft_fatal("bad team");
	}
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
	{
		ft_printf("GAUCHE : %i\n", move_side);
		e->actions = ft_queue_push(e->actions, ft_strdup("gauche"));
	}
	else if (move_side > 0)
	{
		ft_printf("DROITE : %i\n", move_side);
		e->actions = ft_queue_push(e->actions, ft_strdup("droite"));
	}
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

void	ft_see(char *recv_buf, t_env *e, t_tcpsock *server)
{
	void	*action;
	char	**split;
	int		i;

	if (e->waits == NULL)
		ft_fatal("'ok' received, but nothing is in the waitings queue.");
	action = ft_queue_pop(&e->waits);
	recv_buf[ft_strlen(recv_buf) - 1] = 0;
	recv_buf++;
	split = ft_strsplit(recv_buf, ',');
	i = 0;
	while (split[i])
	{
		if (strstr(split[i], "nourriture"))
		{
			if (ft_track(i, e))
				FD_SET(server->sock, &e->write_fds);
			break ;
		}
		i++;
	}
	ft_putendl(recv_buf);
	ft_split_destroy(split);
	ft_memdel(&action);
}

void	ft_receive_data(char *recv_buf, t_env *e, t_tcpsock *server)
{
	void		*data;

	if (ft_strequ(recv_buf, "BIENVENUE"))
		ft_welcome(e, server);
	else if (recv_buf[0] == '{' && ft_strequ(e->waits->tail->data, "voir"))
		ft_see(recv_buf, e, server);
	else if (ft_strequ(recv_buf, "ok"))
	{
		ft_putendl("OKOK");
		data = ft_queue_pop(&e->waits);
		ft_memdel(&data);
	}
	else
		ft_printf("UNKNOW DATA : %s\n", recv_buf);
	if (e->actions == NULL && e->waits == NULL)
	{
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
		if (ft_strequ(action, "voir"))
			ft_putendl_fd("voir", server->sock);
		else if (ft_strequ(action, "avance"))
		{
			ft_putendl("avance");
			ft_putendl_fd("avance", server->sock);
		}
		else if (ft_strequ(action, "gauche"))
		{
			ft_putendl("gauche");
			ft_putendl_fd("gauche", server->sock);
		}
		else if (ft_strequ(action, "droite"))
		{
			ft_putendl("droite");
			ft_putendl_fd("droite", server->sock);
		}
		else if (ft_strncmp(action, "prend ", 6) == 0)
		{
			ft_putendl("prend");
			ft_putendl_fd(action, server->sock);
		}
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
				ft_fatal("SERVER CRASHED.");
			ft_receive_data(recv_buf, e, server);
			ft_strdel(&recv_buf);
			FD_ZERO(&e->read_fds);
		}
		else if (FD_ISSET(server->sock, &e->write_fds))
		{
			if (ft_queue_len(e->waits) < 9)
			{
				ft_send_data(e, server);
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
	ft_vision_init(&e);
	server = ftsock_create(FTSOCK_CLIENT, argv[1], ft_atoi(argv[2]));
	ftsock_connect(server);
	if (server->error)
		ftsock_perror(server->error);
	ft_main_loop(&e, server);
	ftsock_destroy(&server);
	return (0);
}
