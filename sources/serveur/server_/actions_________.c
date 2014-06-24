/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_________.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:48:01 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:48:02 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						prepare_move(int lrf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	if (lrf == L)
		e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = MOVELEFT;
	if (lrf == R)
		e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = MOVERIGHT;
	if (lrf == FW)
		e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = MOVEFW;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].lrf = lrf;
	return (1);
}

int						move_(t_env *e, int pl, int lrf)
{
	if (lrf == FW)
	{
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit--;
		if (e->pl[pl].dir == 1)
			e->pl[pl].y = (e->pl[pl].y + 1) % e->map.ylen;
		if (e->pl[pl].dir == 0 || e->pl[pl].dir == 4)
			e->pl[pl].x = (e->pl[pl].x + 1) % e->map.xlen;
		if (e->pl[pl].dir == 2)
			e->pl[pl].x = (e->pl[pl].x - 1) % e->map.xlen;
		if (e->pl[pl].dir == 3)
			e->pl[pl].y = (e->pl[pl].y - 1) % e->map.ylen;
		if (e->pl[pl].x < 0)
			e->pl[pl].x = e->map.xlen + e->pl[pl].x;
		if (e->pl[pl].y < 0)
			e->pl[pl].y = e->map.ylen + e->pl[pl].y;
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit++;
	}
	e->pl[pl].updated = 1;
	send_res(pl, "ok", e);
	return (1);
}

int						move(t_env *e, int pl)
{
	int					lrf;

	lrf = e->pl[pl].lrf;
	if (lrf == L)
	{
		e->pl[pl].dir = (e->pl[pl].dir + 1) % 4;
	}
	if (lrf == R)
	{
		e->pl[pl].dir = (e->pl[pl].dir - 1) % 4;
	}
	if (e->pl[pl].dir < 0)
		e->pl[pl].dir = 4 + e->pl[pl].dir;
	return (move_(e, pl, lrf));
}

int						getnumb(char *str, int n, char c)
{
	char				**split;
	int					res;

	split = ft_strsplit(str, ' ');
	res = 0;
	if (c != 0)
		(void)c;
	if (n <= (int)ft_sstrlen(split))
		res = ft_atoi(split[n]);
	sstrmemdel(&split);
	return (res);
}

int						change_pos(char *buf, t_env *e, int cs)
{
	int					x;
	int					y;
	int					dir;

	x = getnumb(buf, 0, 0);
	y = getnumb(buf, 1, 0);
	dir = getnumb(buf, 2, 0);
	e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit--;
	e->pl[e->fds[cs].pl].x = x;
	e->pl[e->fds[cs].pl].y = y;
	e->pl[e->fds[cs].pl].dir = dir;
	e->pl[e->fds[cs].pl].lvl = getnumb(buf, 3, 0);
	e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit++;
	return (1);
}
