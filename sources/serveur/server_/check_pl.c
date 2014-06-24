/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:11:16 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:11:17 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void		check_pl_(t_env *e, int i, int tmp, time_t tloc)
{
	if (e->pl[i].cact > 0)
	{
		if (time(&tloc) - e->pl[i].timer
			> (getacttime(e->pl[i].action[0]) / e->time_unit))
		{
			load_function(e->pl[i].action[0], i, e);
			while (tmp < e->pl[i].cact)
			{
				e->pl[i].action[tmp] = e->pl[i].action[tmp + 1];
				tmp++;
			}
			e->pl[i].cact--;
			if (e->pl[i].cact > 0)
				e->pl[i].timer = time(&tloc);
		}
	}
	if (e->pl[i].updated)
	{
		g_send_pl(e->pl[i], i, e);
		e->pl[i].updated = 0;
	}
	return ;
}

void		check_pl(int *check, t_env *e, int i, int tmp)
{
	time_t	tloc;

	if (time(&tloc) - e->general_timer > 126 / e->time_unit)
	{
		if (e->pl[i].r[0] > 0)
		{
			e->pl[i].r[0]--;
			*check = 1;
		}
		else
			e->pl[i].alive = 0;
	}
	check_pl_(e, i, tmp, tloc);
	return ;
}

void		check_wpl(t_env *e, int i, int tmp)
{
	if (e->teams[e->fds[e->waitingpl[i]].team].nbpl < e->maxpl)
	{
		e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
		e->fds[e->waitingpl[i]].pl = e->nbpl;
		new_tpl(e, e->waitingpl[i], 1,
			&e->pl[e->fds[e->waitingpl[i]].pl]);
		e->nbpl++;
		e->tnbpl++;
		e->teams[e->fds[e->waitingpl[i]].team].nbpl++;
		e->wpl--;
	}
	else if (e->teams[tmp].forknb > 0)
	{
		e->fds[e->waitingpl[i]].pl = e->teams[tmp].fork[e->teams[tmp].forknb
			- 1];
		new_tpl(e, e->waitingpl[i],
			0, &e->pl[e->teams[tmp].fork[e->teams[tmp].forknb - 1]]);
		e->teams[tmp].forknb--;
		e->wpl--;
	}
}
