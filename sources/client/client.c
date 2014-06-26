/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:18:15 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/26 19:47:46 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

void	ft_fuck_norme(t_env *e, char *recv_buf, t_tcpsock *server)
{
	if (get_next_line(server->sock, &recv_buf) <= 0)
		ft_end(e, recv_buf, server, "SERVER CRASHED !");
	ft_printf("RECEIVE : %s\n", recv_buf);
	ft_receive_data(recv_buf, e, server);
	ft_strdel(&recv_buf);
	FD_ZERO(&e->read_fds);
}

void	ft_main_loop(t_env *e, t_tcpsock *server)
{
	char		*recv_buf;

	recv_buf = NULL;
	FD_ZERO(&e->write_fds);
	FD_ZERO(&e->read_fds);
	while (42)
	{
		FD_SET(server->sock, &e->read_fds);
		select(server->sock + 1, &e->read_fds, &e->write_fds, NULL, NULL);
		if (FD_ISSET(server->sock, &e->read_fds))
			ft_fuck_norme(e, recv_buf, server);
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
