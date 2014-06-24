/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:18:15 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/24 22:38:16 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_main_loop(t_env *e, t_tcpsock *server)
{
	fd_set		read_fds;
	fd_set		write_fds;
	char		*recv_buf;

	FD_ZERO(&write_fds);
	FD_ZERO(&read_fds);
	FD_SET(server->sock, &read_fds);
	while (42)
	{
		select(server->sock + 1, &read_fds, &write_fds, NULL, NULL);
		if (FD_ISSET(server->sock, &read_fds))
		{
			/* RECV DATA */
			get_next_line(server->sock, &recv_buf);
			ft_strdel(&recv_buf);
		}
		else if (FD_ISSET(server->sock, &write_fds))
		{
			/* SEND DATA */
			FD_ZERO(&write_fds);
		}
	}
	(void)e;
}

int		main(int argc, char **argv)
{
	t_env			e;
	t_tcpsock		*server;

	if (argc != 5)
		ft_fatal("Usage: ./client <ip/dns> <port> <team> <name>");
	e.team = argv[3];
	ft_memcpy(e.name, argv[4], 4);
	server = ftsock_create(FTSOCK_CLIENT, argv[1], ft_atoi(argv[2]));
	ftsock_connect(server);
	if (server->error)
		ftsock_perror(server->error);
	ft_main_loop(&e, server);
	ftsock_destroy(&server);
	return (0);
}
