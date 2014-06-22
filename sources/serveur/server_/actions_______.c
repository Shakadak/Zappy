/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_______.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:20:46 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:20:47 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						check_ressources(int *ressources,
	int x, int y, t_env *e)
{
	int					i;
	int					c;

	i = 1;
	c = 0;
	while (i < NBRESSOURCE)
	{
		if (e->map.map[y][x].r[i] >= ressources[i])
			c++;
		i++;
	}
	i = 1;
	if (c == NBRESSOURCE - 1)
	{
		while (i < NBRESSOURCE)
		{
			e->map.map[y][x].r[i] -= ressources[i];
			i++;
		}
		return (1);
	}
	return (0);
}

void					incantation_pl(char **res, char **tograph, t_env *e,
	int pl)
{
	int					i;
	int					j;

	i = 0;
	j = -1;
	while (i < (e->pl[pl].lvl - 1) && ++j < e->nbpl)
	{
		if (e->pl[j].y == e->pl[pl].y && e->pl[j].x == e->pl[pl].x
			&& j != pl)
		{
			*tograph = ft_stradd(*tograph, " #");
			*tograph = ft_straddrp(*tograph, ft_itoa(j));
			*res = ft_strclone("elevation en cours");
			*res = ft_stradd(*res, " niveau actuel : ");
			*res = ft_straddrp(*res, ft_itoa(e->pl[j].lvl + 1));
			if (e->pl[j].cact < WACT)
			{
				e->pl[j].action[e->pl[j].cact] = LVLUP;
				e->pl[j].cact++;
			}
			send_res(j, *res, e);
			ft_memdel((void **)res);
			i++;
		}
	}
}
