/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions___.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:15:16 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:15:17 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void					eject_(int j, int pl, t_env *e)
{
	char				*res;
	int					tmpx;
	int					tmpy;

	res = NULL;
	tmpx = 0;
	tmpy = 0;
	tmpx = (cos(e->pl[pl].dir * (M_PI / 2))) * EJECTPOWA;
	tmpy = (sin(e->pl[pl].dir * (M_PI / 2))) * EJECTPOWA;
	e->pl[j].x = (int)(e->pl[j].x + tmpx)
		% e->map.xlen;
	e->pl[j].y = (int)(e->pl[j].y + tmpy)
		% e->map.ylen;
	res = ft_strclone("deplacement ");
	res = ft_straddrp(res, ft_itoa(getdir((e->pl[pl].x - e->pl[j].x),
		(e->pl[pl].y - e->pl[j].y), j, e)));
	send_res(j, res, e);
	e->pl[j].updated = 1;
	free(res);
	res = NULL;
	e->map.map[e->pl[j].y][e->pl[j].x].plonit += 1;
	return ;
}

void					eject__(int pl, t_env *e)
{
	char				*res;

	res = NULL;
	send_res(pl, "ok", e);
	res = ft_strclone("pex #");
	res = ft_straddrp(res, ft_itoa(pl));
	send_res(-1, res, e);
	free(res);
	res = NULL;
	return ;
}

int						eject(t_env *e, int pl)
{
	int					nbpl;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit > 1)
	{
		nbpl = e->map.map[e->pl[pl].y][e->pl[pl].x].plonit;
		while (i < nbpl && j < e->nbpl)
		{
			if (e->pl[j].y == e->pl[pl].y && e->pl[j].x == e->pl[pl].x
				&& j != pl)
			{
				eject_(j, pl, e);
				i++;
			}
			j++;
		}
		eject__(pl, e);
		e->map.map[e->pl[pl].y][e->pl[pl].x].plonit -= i;
	}
	else
		send_res(pl, "ko", e);
	return (1);
}

int						prepare_eject(t_env *e, int cs)
{
	int					pl;

	pl = e->fds[cs].pl;
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit > 1)
	{
		e->pl[e->fds[cs].pl].actionwait = 1;
		e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = EJECT;
		e->pl[e->fds[cs].pl].cact++;
	}
	return (1);
}
