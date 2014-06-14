/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:17:34 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:17:35 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "bircd.h"

void						srv_accept(t_env *e, int s)
{
	int						cs;
	struct sockaddr_in		csin;
	socklen_t				csin_len;
	char					buf[4096];

	csin_len = sizeof(csin);
	cs = X(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
	e->fds[cs].nicktrue = 0;
	e->fds[cs].nick = NULL;
	e->fds[cs].noteam = 1;
	memcpy(buf, "BIENVENUE\n", BUF_SIZE);
	write(cs, buf, ft_strlen(buf));
	ft_putstr("cs:");
	ft_putstr(ft_itoa(cs));
	ft_putstr("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
	if (e->forknb > 0)
	{
		ft_putstr("FORKNB");
		e->fds[cs].pl = e->fork[e->forknb];
		e->pl[e->fork[e->forknb]].cs = cs;
		e->forknb--;
	}
	else
	{
		if (e->waitingpl == NULL)
		{
			e->wpl = 0;
			e->waitingpl = (int *)malloc(sizeof(int) * 1);
		}
		else
			e->waitingpl = (int *)realloc(e->waitingpl, (sizeof(int)
				* (e->wpl + 1)));
		e->waitingpl[e->wpl] = cs;
		e->wpl++;
		e->fds[cs].pl = -1;
	}
	return ;
//faire le connect et mettre une liste en attente de pl a connecter,
//voir exactement pourquoi le connect_nbr
//graphic
//e->eggs[] malloc int * 1;
//e->nbegg 0;
//e->map.ylen = arg;
//e->map.xlen = arg;
//e->map->map[][].egg 0
//				.plonit 0
//				.r[NB_RESSOURCE + 1] 0 // pui generation food etant la case 6
//e->teams malloc t_team 1
//e->teams.max 0
//e->teams.nbpl 0
//e->pl[] malloc t_pl * 1;
//e->pl.r[NB_RESSOURCE + 1] 0 // sauf case 6 qui elle est mise a START_FOOD;
//e->pl.action = 0;
//e->pl.actionwait = 0;
//e->pl.x 0
//e->pl.y 0
//e->pl.bc char * NULL
//e->pl.dir double? 0
//e->pl.updated 0
//e->nbpl 0;
//e->map.updated 0
//
}
