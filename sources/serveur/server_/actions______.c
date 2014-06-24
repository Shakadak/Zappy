/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions______.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:15:44 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:15:45 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						prepare_broadcast(char *buf, t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = BROADCAST;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].bc = ft_strclone(buf);
	return (1);
}

double					getdir_(double x, double y, double norm, int dir)
{
	double				tmpx;
	double				tmpy;
	double				angl;

	tmpx = (double)x / (norm);
	tmpy = (double)y / (norm);
	if (tmpx != 0 && tmpy != 0)
	{
		if (tmpy < 0)
			angl = acos(tmpx) * (-1);
		if (tmpy >= 0)
			angl = acos(tmpx);
	}
	else if (tmpx == 0)
		angl = (M_PI / 2) * tmpy;
	else if (tmpy == 0 && tmpx == 1)
		angl = 0;
	else if (tmpy == 0 && tmpx == -1)
		angl = M_PI;
	angl -= (M_PI / 2) * dir;
	while (angl < 0)
		angl += (M_PI * 2);
	while (angl > (M_PI * 2))
		angl -= (M_PI * 2);
	return (angl);
}

int						getdir(double x, double y, int pl, t_env *e)
{
	double				res;
	double				angl;
	double				norm;

	norm = sqrt(square(x) + square(y));
	res = 0;
	angl = 0;
	if (norm == 0)
		return (0);
	if (norm > 0)
	{
		angl = getdir_(x, y, norm, e->pl[pl].dir);
		while (res < 9)
		{
			if (res == 8)
				return (1);
			if (angl >= (((M_PI / 4) * res) - (double)((M_PI * 2) / 16))
				&& angl <= ((M_PI / 4) * (res + 1)) - (double)((M_PI * 2) / 16))
				return (res + 1);
			res++;
		}
	}
	return (res);
}
