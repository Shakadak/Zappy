/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:00:10 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:00:11 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void					aff_map___(char **toaff, t_env *e)
{
	int					x;
	int					y;
	char				c;

	x = 0;
	y = 0;
	c = 0;
	y = e->map.ylen;
	while (--y >= 0)
	{
		while (toaff[y][x] != '\0')
		{
			c = toaff[y][x];
			ft_putchar(c);
			ft_putstr("\t");
			x++;
		}
		x = 0;
		ft_putstr("\n");
	}
}

char					*seecaselvl(int lvl, int pl, t_env *e)
{
	e->pl[pl].x = getrc(e->pl[pl].x, 'X', e);
	e->pl[pl].y = getrc(e->pl[pl].y, 'Y', e);
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == UP)
		return (check_cases_up(e, ((e->pl[pl].y
		+ lvl + 1) % e->map.ylen), e->pl[pl].x, lvl + 1));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == DOWN)
		return (check_cases_down(e, ((e->pl[pl].y
		- lvl - 1) % e->map.ylen), e->pl[pl].x, (lvl + 1)));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == LEFT)
		return (check_cases_left(e, e->pl[pl].y, ((e->pl[pl].x
		- 1 - lvl) % e->map.xlen), (lvl + 1)));
	if (((e->pl[pl].dir % 4) * (M_PI / 2)) == RIGHT
		|| ((e->pl[pl].dir % 4) * (M_PI / 2)) == (2 * M_PI))
		return (check_cases_right(e, e->pl[pl].y, ((e->pl[pl].x
		+ 1 + lvl) % e->map.xlen), (lvl + 1)));
	return (NULL);
}

void					prepare_debug(int i, t_env *e)
{
	int					j;

	j = 0;
	while (i < e->map.ylen)
	{
		j = 0;
		while (j < e->map.xlen)
		{
			e->debug[i][j] = '-';
			j++;
		}
		i++;
	}
}

int						see(t_env *e, int pl)
{
	int					lv;
	char				*res;

	lv = e->pl[pl].lvl;
	res = NULL;
	res = ft_strclone("{");
	res = ft_straddrp(res, lookoncase(e, e->pl[pl].y, e->pl[pl].x, 0));
	while (lv > 0)
	{
		res = ft_stradd(res, ", ");
		res = ft_straddrp(res, seecaselvl((e->pl[pl].lvl - lv), pl, e));
		lv--;
	}
	res = ft_stradd(res, "}");
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}
