/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 11:45:52 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/18 11:45:54 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "libft.h"
#include "ftp.h"
#include "bircd.h"

static int					main__(int i, t_env e)
{
	while (1)
	{
		FD_ZERO(&e.fd_read);
		FD_ZERO(&e.fd_write);
		i = 0;
		while (i < e.maxfd)
		{
			if (e.fds[i].type != FD_FREE)
			{
				FD_SET(i, &e.fd_read);
				if (strlen(e.fds[i].buf_write))
					FD_SET(i, &e.fd_write);
				e.max = MAX(e.max, i);
			}
			i++;
		}
		do_select(&e);
		check_fd(&e);
	}
	return (0);
}

static int					main_(int socket_desc)
{
	t_env					e;
	struct rlimit			rlp;
	int						i;

	i = 0;
	e.servsocket = socket_desc;
	getrlimit(RLIMIT_NOFILE, &rlp);
	e.maxfd = rlp.rlim_cur;
	e.fds = (t_fd *)malloc(sizeof(t_fd) * e.maxfd);
	e.fds[0].fct_read = read_zero;
	e.fds[socket_desc].fct_read = read_socket;
	e.fds[0].type = FD_CLIENT;
	e.fds[socket_desc].type = FD_CLIENT;
	return (main__(i, e));
}

int							main(int argc, char **argv)
{
	t_connect				server;
	t_servaddress			address;
	int						socket_desc;

	server.proto = getprotobyname("tcp");
	server.read_size = 0;
	if (argc != 3)
		return (0);
	address.ip = ft_strclone(argv[1]);
	address.port = ft_atoi(argv[2]);
	socket_desc = socket(PF_INET, SOCK_STREAM, server.proto->p_proto);
	server.serv.sin_family = AF_INET;
	server.serv.sin_addr.s_addr = inet_addr(address.ip);
	server.serv.sin_port = htons(address.port);
	if (connect(socket_desc, (struct sockaddr *)&server.serv,
		sizeof(server.serv)) < 0)
	{
		ft_putstr("Connection error, maybe your stupid");
		ft_putstr("and entered wrong server address.");
		return (1);
	}
	ft_putstr("??");
	return (main_(socket_desc));
}
