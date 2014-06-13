/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:42:38 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 04:42:39 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "bircd.h"

static void				who_is_here__(int cs, char **tosend, int c)
{
	char				*data;

	if (c > 0)
	{
		data = concatenate(tosend, '\n');
		sstrmemdel(&tosend);
		send_data_to_socket(cs, data, ft_strlen(data));
		ft_memdel((void **)&data);
	}
	return ;
}

static void				who_is_here_(t_env *e, int cs, int c)
{
	int					i;
	char				**tosend;

	i = 0;
	tosend = (char **)malloc(sizeof(char *) * (c + 1));
	c = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].chan != NULL && e->fds[cs].chan != NULL)
		{
			if ((e->fds[i].type == FD_CLIENT)
				&& !ft_strcmp(e->fds[i].chan, e->fds[cs].chan)
				&& e->fds[i].chan != NULL && e->fds[i].nick != NULL)
			{
				tosend[c] = ft_strclone(e->fds[i].nick);
				tosend[c + 1] = '\0';
				c++;
			}
		}
		i++;
	}
	who_is_here__(cs, tosend, c);
}

void					who_is_here(t_env *e, int cs)
{
	int					i;
	int					c;

	i = 0;
	c = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].chan != NULL)
		{
			if ((e->fds[i].type == FD_CLIENT) &&
				(i != cs) && !ft_strcmp(e->fds[i].chan, e->fds[cs].chan)
				&& e->fds[i].chan != NULL && e->fds[i].nick != NULL)
				c++;
		}
		i++;
	}
	who_is_here_(e, cs, c);
}

void					send_msg(t_env *e, int cs)
{
	char				*nick;
	int					i;
	char				*message;

	nick = get_data_from_socket(cs);
	message = get_data_from_socket(cs);
	i = -1;
	while (++i < e->maxfd)
	{
		if (e->fds[i].nick != NULL)
		{
			if ((e->fds[i].type == FD_CLIENT) &&
					(i != cs) && !ft_strcmp(nick, e->fds[i].nick))
			{
				send_data_to_socket(i, e->fds[cs].nick,
					ft_strlen(e->fds[cs].nick));
				send_data_to_socket(i, " : ", 3);
				send_data_to_socket(i, message, ft_strlen(message));
				send_data_to_socket(i, "\n", 1);
			}
		}
	}
	ft_memdel((void **)&nick);
	ft_memdel((void **)&message);
	return ;
}

void					send_to_all(t_env *e, int cs)
{
	char				*message;
	int					i;

	message = get_data_from_socket(cs);
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[cs].chan != NULL && e->fds[i].chan != NULL)
		{
			if ((e->fds[i].type == FD_CLIENT) &&
					(i != cs) && !ft_strcmp(e->fds[cs].chan, e->fds[i].chan))
			{
				send_data_to_socket(i, e->fds[cs].nick,
					ft_strlen(e->fds[cs].nick));
				send_data_to_socket(i, ">", 1);
				send_data_to_socket(i, message, ft_strlen(message));
				send_data_to_socket(i, "\n", 1);
			}
		}
		i++;
	}
	if (ft_strlen(message))
		free(message);
	message = NULL;
	return ;
}
