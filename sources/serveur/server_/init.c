/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:06:28 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:06:29 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void		init_graph_(t_env *e, int i)
{
	i = e->wpl;
	while (i > 0)
	{
		if (e->forknb > 0)
		{
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		i--;
	}
	return ;
}

void		init_graph(t_env *e, int cs)
{
	int		i;

	i = 0;
	(void)cs;
	g_send_map(e);
	while (i < e->nbpl)
	{
		if (e->pl[i].cs >= 0)
			g_send_pl(e->pl[i], i, e);
		e->pl[i].updated = 0;
		i++;
	}
	i = e->nbegg;
	while (i > 0)
	{
		if (!e->eggs[i].used)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		i--;
	}
	init_graph_(e, i);
	return ;
}

void		init_food(t_pl *pl)
{
	int		i;

	i = 1;
	pl->r[0] = START_FOOD;
	while (i < 7)
	{
		pl->r[i] = 0;
		i++;
	}
	return ;
}

void		new_tpl(t_env *e, int cs, int newpl, t_pl *res)
{
	if (newpl)
	{
		res->x = rand() % e->map.xlen;
		res->y = rand() % e->map.ylen;
		init_food(res);
		res->dir = (rand() % 4) * (M_PI / 2);
		e->map.map[res->y][res->x].plonit++;
	}
	res->action[0] = 0;
	res->cact = 0;
	res->actionwait = 0;
	res->bc = NULL;
	res->updated = 1;
	res->cs = cs;
	res->lvl = 1;
	res->timer = 0;
	res->what = 0;
	res->team = 0;
	res->alive = 1;
	return ;
}

t_pl		new_pl(t_env *e, t_egg egg, int id)
{
	t_pl	res;

	res.x = egg.x;
	res.y = egg.y;
	e->map.map[egg.y][egg.y].plonit++;
	res.action[0] = 0;
	res.cact = 0;
	res.actionwait = 0;
	res.bc = NULL;
	res.updated = 1;
	init_food(&res);
	res.dir = (rand() % 4) * (M_PI / 2);
	res.cs = -1;
	res.lvl = 1;
	res.timer = 0;
	res.cact = 0;
	res.alive = 1;
	res.what = 0;
	res.team = e->fds[e->pl[egg.pl].cs].team;
	e->teams[res.team].fork = (int *)realloc(e->teams[res.team].fork,
		(sizeof(int) * (e->teams[res.team].forknb + 1)));
	e->teams[res.team].fork[e->teams[res.team].forknb] = id;
	e->teams[res.team].forknb++;
	return (res);
}
