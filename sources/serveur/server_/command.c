/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:42:26 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 04:42:27 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "bircd.h"

void					joinchan(t_env *e, int cs)
{
	e->fds[cs].chan = get_data_from_socket(cs);
	send_data_to_socket(cs, "Joined new channel.",
		ft_strlen("Joined new channel."));
}

void					recnick(t_env *e, int cs)
{
	char				*nick;

	nick = get_data_from_socket(cs);
	if (src(nick, e->nicknames) == NULL)
	{
		ft_putstr("null");
		if (e->fds[cs].nicktrue)
		{
			ft_putstr("cte pas nul ?");
			rec(NULL, e->fds[cs].nick, e->nicknames);
			free(e->fds[cs].nick);
			e->fds[cs].nick = NULL;
		}
		ft_putstr("ok free");
		rec("pris", nick, e->nicknames);
		ft_putstr("ok rec");
		e->fds[cs].nicktrue = 1;
		e->fds[cs].nick = ft_strclone(nick);
		send_data_to_socket(cs, "Ok.", ft_strlen("Ok."));
	}
	else
		send_data_to_socket(cs,
			"Sorry, nickname already registered try again x).",
	ft_strlen("Sorry, nickname already registered try again x)."));
	ft_putstr("fin");
}

void					ft_putsstr(char **sstr)
{
	int					i;

	i = 0;
	while (sstr[i] != '\0')
	{
		ft_putstr(sstr[i]);
		i++;
	}
	return ;
}

char					*concatenate(char **sstr, char c)
{
	char				*res;
	int					i;

	i = 1;
	res = ft_strclone(sstr[0]);
	res = ft_stradd(res, &c);
	while (sstr[i] != '\0')
	{
		res = ft_stradd(res, sstr[i]);
		res = ft_stradd(res, &c);
		i++;
	}
	return (res);
}
