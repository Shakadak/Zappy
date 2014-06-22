/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:12:32 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:12:33 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void			rand_generate(t_env *e)
{
	static int	seed = 0;
	int			i;
	int			seednb;

	i = 0;
	srand(seed);
	seed += 3;
	seednb = rand() % 4;
	while (i < seednb)
	{
		e->map.map[rand() %
			e->map.ylen][rand() % e->map.xlen].r[rand() % NBRESSOURCE] += i % 1;
		i++;
	}
	return ;
}

void			serv_update__(t_env *e, int tmp, int i, time_t tloc)
{
	i = e->wpl - 1;
	while (i >= 0)
	{
		if (e->forknb > 0 && e->fds[e->waitingpl[i]].pl >= -1)
		{
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		else if (!e->fds[e->waitingpl[i]].noteam && e->fds[e->waitingpl[i]].pl
			>= -1)
		{
			tmp = e->fds[e->waitingpl[i]].team;
			check_wpl(e, i, tmp);
		}
		i--;
	}
	if (time(&tloc) - e->generation_timer > (GENE_TIME / e->time_unit))
	{
		rand_generate(e);
		e->generation_timer = time(&tloc);
	}
	return ;
}

void			serv_update_(t_env *e, int tmp, int i, time_t tloc)
{
	i = e->nbegg - 1;
	while (i >= 0)
	{
		if (e->eggs[i].updated)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		if (time(&tloc) - e->eggs[i].timer >= (EGG_TIME / e->time_unit)
			&& !e->eggs[i].used)
		{
			tloc = 0;
			e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
			e->pl[e->nbpl] = new_pl(e, e->eggs[i], e->nbpl);
			e->pl[e->nbpl].cs = -1;
			e->pl[e->nbpl].updated = 1;
			e->map.map[e->eggs[i].y][e->eggs[i].x].egg--;
			e->nbpl++;
			e->eggs[i].used = 1;
			tloc = 0;
		}
		i--;
	}
	serv_update__(e, tmp, i, tloc);
}

void			serv_update(t_env *e)
{
	int			i;
	time_t		tloc;
	int			tmp;
	int			check;

	i = 0;
	tmp = 0;
	tloc = 0;
	check = 0;
	while (i < e->nbpl)
	{
		if (e->pl[i].alive)
			check_pl(&check, e, i, tmp);
		i++;
	}
	if (check)
		e->general_timer = time(&tloc);
	if (e->map.updated)
		g_send_map(e);
	serv_update_(e, tmp, i, tloc);
}
