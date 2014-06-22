/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_____.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:15:31 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:15:32 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						send_bc_to_pl(int pl, int dir, char *tosend, t_env *e)
{
	char				*res;

	res = ft_strclone("message ");
	res = ft_straddrp(res, ft_itoa(dir));
	res = ft_stradd(res, ", ");
	res = ft_stradd(res, tosend);
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}

void					broadcast___(t_env *e, int i, int pl, int x)
{
	int					y;
	int					v1;
	int					v2;

	y = e->pl[pl].y;
	v1 = 0;
	v2 = 0;
	y = e->pl[pl].y;
	while ((y + v1) % e->map.ylen != e->pl[i].y)
		v1++;
	y = e->pl[i].y;
	while ((y + v2) % e->map.ylen != e->pl[pl].y)
		v2++;
	if (v1 > v2)
		y = v2;
	else
		y = -v1;
	send_bc_to_pl(i, getdir(x, y, i, e), e->pl[pl].bc, e);
}

void					broadcast__(t_env *e, int i, int pl)
{
	int					v2;
	int					v1;
	int					x;

	v2 = 0;
	v1 = 0;
	x = e->pl[pl].x;
	while ((x + v1) % e->map.xlen != e->pl[i].x)
		v1++;
	x = e->pl[i].x;
	while ((x + v2) % e->map.xlen != e->pl[pl].x)
		v2++;
	if (v1 > v2)
		x = +v2;
	else
		x = -v1;
	broadcast___(e, i, pl, x);
}

int						broadcast_(t_env *e, int pl)
{
	char				*tmp;
	int					i;

	i = 0;
	while (i < e->nbpl)
	{
		if (i != pl)
			broadcast__(e, i, pl);
		i++;
	}
	send_res(pl, "ok", e);
	tmp = ft_strclone("pbc #");
	tmp = ft_straddrp(tmp, ft_itoa(pl));
	tmp = ft_stradd(tmp, " ");
	tmp = ft_stradd(tmp, e->pl[pl].bc);
	send_res(-1, tmp, e);
	free(tmp);
	tmp = NULL;
	free(e->pl[pl].bc);
	e->pl[pl].bc = NULL;
	return (1);
}
