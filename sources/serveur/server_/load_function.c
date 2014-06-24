/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:04:35 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:04:40 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void	load_function_(int action, int pl, t_env *e)
{
	if (action == FORK)
		fork_player(e, pl);
	if (action == INCANTATION)
		incantation(e, pl);
	if (action == CNB)
		connect_nbr(e, pl);
	if (action == BROADCAST)
		broadcast_(e, pl);
	if (action == LVLUP)
		lvl_up(e, pl);
	if (action == INV)
		aff_inv(e, pl);
	if (action == SEE)
		see(e, pl);
}

void	load_function(int action, int pl, t_env *e)
{
	if (action == MOVELEFT)
	{
		e->pl[pl].lrf = L;
		move(e, pl);
	}
	if (action == MOVERIGHT)
	{
		e->pl[pl].lrf = R;
		move(e, pl);
	}
	if (action == MOVEFW)
	{
		e->pl[pl].lrf = FW;
		move(e, pl);
	}
	if (action == TAKE)
		take(e, pl);
	if (action == DROP)
		drop(e, pl);
	if (action == EJECT)
		eject(e, pl);
	load_function_(action, pl, e);
}

int		getacttime(int action)
{
	int	res;

	if (action == MOVE)
		res = 7;
	if (action == TAKE)
		res = 7;
	if (action == DROP)
		res = 7;
	if (action == EJECT)
		res = 7;
	if (action == FORK)
		res = 42;
	if (action == INCANTATION)
		res = 300;
	if (action == CNB)
		res = 0;
	if (action == BROADCAST)
		res = 7;
	if (action == LVLUP)
		res = 300;
	if (action == INV)
		res = 1;
	if (action == SEE)
		res = 7;
	return (res);
}
