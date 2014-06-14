/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:04:28 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 04:04:29 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "ftp.h"
#include "libft.h"
#include "bircd.h"

int							cmdfound(char *cmd, char *message, int socket_desc)
{
	if (!ft_strcmp(cmd, "/nick"))
		return (ft_handle_nick(&message[6], socket_desc));
	if (!ft_strcmp(cmd, "/join"))
		return (ft_handle_join(&message[6], socket_desc));
	if (!ft_strcmp(cmd, "/who"))
		return (ft_handle_who(&message[5], socket_desc));
	if (!ft_strcmp(cmd, "/msg"))
		return (ft_handle_msg(&message[5], socket_desc));
	else
		return (0);
}

void						select_cmd(char *message, int socket_desc)
{
	char					*tmp;
	int						i;
	int						check;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(message));
	check = 0;
	while (message[i] != '\0')
	{
		tmp[i] = message[i];
		tmp[i + 1] = '\0';
		if (cmdfound(tmp, message, socket_desc))
		{
			check = 1;
			free(tmp);
			tmp = NULL;
			return ;
		}
		i++;
	}
	ft_memdel((void **)&tmp);
	if (check == 0)
		ft_handle_all(message, socket_desc);
	ft_putstr("\n");
	ft_putstr("o.O>");
}

void						read_zero(t_env *e, int i)
{
	int						test;

	test = read(i, &e->fds[i].buf_read, 4096);
	e->fds[i].buf_read[test - 1] = '\0';
	write(e->servsocket, e->fds[i].buf_read, 4096);
	e->fds[i].buf_read[0] = '\0';
}

void						read_socket(t_env *e, int i)
{
	char					res[4096];
	int						j;

	(void)e;
	j = read(i, &res, 4096);
	res[j - 1] = '\0';
	ft_putstr(res);
	res[0] = '\0';
	return ;
}
