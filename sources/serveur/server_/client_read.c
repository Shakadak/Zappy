/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:16:08 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:16:10 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "bircd.h"
#include "libft.h"

void					check_op(char *tmp, t_env *e, int cs, char *buf)
{
	if (!ft_strcmp(tmp, "avance"))
		prepare_move(FW, e, cs);
	if (!ft_strcmp(tmp, "droite"))
		prepare_move(R, e, cs);
	if (!ft_strcmp(tmp, "gauche"))
		prepare_move(L, e, cs);
	if (!ft_strcmp(tmp, "voir"))
		prepare_see(e, cs);
	if (!ft_strcmp(tmp, "inventaire"))
		prepare_inv(e, cs);
	if (!ft_strcmp(tmp, "prend "))
		prepare_take(&buf[6], e, cs);
	if (!ft_strcmp(tmp, "pose "))
		prepare_drop(&buf[5], e, cs);
	if (!ft_strcmp(tmp, "expulse"))
		prepare_eject(e, cs);
	if (!ft_strcmp(tmp, "broadcast "))
		prepare_broadcast(&buf[10], e, cs);
	if (!ft_strcmp(tmp, "incantation"))
		prepare_incantation(e, cs);
	if (!ft_strcmp(tmp, "fork"))
		prepare_fork(e, cs);
	if (!ft_strcmp(tmp, "connect_nbr"))
		connect_nbr(e, cs);
}

int						foundop(char *tmp, char *buf, t_env *e, int cs)
{
	time_t				tloc;

	tloc = 0;
	if (e->fds[cs].pl >= 0 && !e->fds[cs].noteam)
	{
		if (e->pl[e->fds[cs].pl].cact < WACT)
		{
			check_op(tmp, e, cs, buf);
			if (e->pl[e->fds[cs].pl].cact == 0 && ft_strcmp(tmp, "connect_nbr"))
				e->pl[e->fds[cs].pl].timer = time(&tloc);
		}
	}
	else if (!ft_strcmp(tmp, "GRAPHIC"))
	{
		connect_graphic(e, cs);
		e->fds[cs].pl = -2;
		return (1);
	}
	else
		return (-1);
	return (-1);
}

int						get_opt_(char *buf, t_env *e, int cs)
{
	int					i;
	char				*tmp;

	tmp = (char *)malloc(sizeof(char) * (lenuntil(buf, ' ') + 1));
	i = 0;
	while (buf[i] != '\0')
	{
		tmp[i] = buf[i];
		tmp[i + 1] = '\0';
		if (foundop(tmp, buf, e, cs) != -1)
			break ;
		i++;
	}
	if (e->fds[cs].noteam == 1 && e->fds[cs].pl >= -1)
	{
		e->fds[cs].noteam = 0;
		e->fds[cs].team = search_team(buf, e, cs);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

void					check_client_pl(t_env *e, int cs)
{
	if (e->fds[cs].pl >= 0)
	{
		e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit--;
		e->pl[e->fds[cs].pl].alive = 0;
		if (!e->fds[cs].noteam)
			e->teams[e->fds[cs].team].nbpl--;
		e->pl[e->fds[cs].pl].team = -1;
		e->tnbpl--;
		e->fds[cs].pl = -1;
	}
}

void					client_read(t_env *e, int cs)
{
	int					r;
	int					i;

	i = 0;
	r = recv(cs, &e->fds[cs].buf_read, 4096, 0);
	if (r <= 0)
	{
		ft_putstr("Client déconnecté.");
		e->fds[cs].type = FD_FREE;
		e->fds[cs].noteam = 1;
		check_client_pl(e, cs);
		i = 0;
		while (i < e->graphnb)
		{
			if (e->graphfd[i] == cs)
				e->graphfd[i] = -1;
			i++;
		}
	}
	else
	{
		e->fds[cs].buf_read[r - 1] = '\0';
		get_opt_(e->fds[cs].buf_read, e, cs);
	}
	return ;
}
