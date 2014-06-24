/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 18:59:58 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:00:01 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

double					square(double nbr)
{
	double				res;

	res = nbr * nbr;
	return (res);
}

int						take(t_env *e, int pl)
{
	if (e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what] > 0)
	{
		e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what]--;
		e->pl[pl].r[e->pl[pl].what]++;
		send_res(pl, "ok", e);
	}
	else
		send_res(pl, "ko", e);
	return (1);
}

int						prepare_take(char *buf, t_env *e, int cs)
{
	if (ft_strlen(buf) > 2)
	{
		e->pl[e->fds[cs].pl].what = get_what(buf);
		ft_putstr(buf);
	}
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = TAKE;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						prepare_drop(char *buf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = DROP;
	e->pl[e->fds[cs].pl].cact++;
	if (ft_strlen(buf) > 2)
		e->pl[e->fds[cs].pl].what = get_what(buf);
	return (1);
}

int						drop(t_env *e, int pl)
{
	if (e->pl[pl].what > 0)
	{
		e->pl[pl].r[e->pl[pl].what]--;
		e->map.map[e->pl[pl].y][e->pl[pl].x].tmpr[e->pl[pl].what]++;
		e->map.map[e->pl[pl].y][e->pl[pl].x].r[e->pl[pl].what]++;
		send_res(pl, "ok", e);
		return (1);
	}
	send_res(pl, "ko", e);
	e->map.updated = 1;
	e->pl[pl].updated = 1;
	return (1);
}
