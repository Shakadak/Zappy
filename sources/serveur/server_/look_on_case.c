/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_on_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:06:39 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:06:40 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

char					*getressource(int rsc)
{
	if (rsc == NOURRITURE)
		return ("nourriture");
	if (rsc == LINEMATE)
		return ("linemate");
	if (rsc == DERAUMERE)
		return ("deraumère");
	if (rsc == SIBUR)
		return ("sibur");
	if (rsc == MENDIANE)
		return ("mendiane");
	if (rsc == PHIRAS)
		return ("phiras");
	if (rsc == THYSTAME)
		return ("thystame");
	return (NULL);
}

char					*get_case_ressource(t_case tmpc, int i, int j,
	char *res)
{
	int					check;

	check = 0;
	while (j < NBRESSOURCE)
	{
		while (i < tmpc.r[j])
		{
			if (!check)
			{
				res = ft_strclone(getressource(j));
				check++;
			}
			else
			{
				res = ft_stradd(res, " ");
				res = ft_stradd(res, getressource(j));
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (!check)
		return (NULL);
	return (res);
}

char					*lookoncase_(int i, t_case tmpc, char *res)
{
	while (i < tmpc.plonit)
	{
		if (res == NULL)
			res = ft_strclone("joueur");
		else
			res = ft_stradd(res, " joueur");
		i++;
	}
	i = 0;
	while (i < tmpc.egg)
	{
		if (res == NULL)
			res = ft_strclone("egg");
		else
			res = ft_stradd(res, " egg");
		i++;
	}
	return (res);
}

int						getrc(int n, char xy, t_env *e)
{
	int					res;

	res = n;
	if (xy == 'X')
	{
		while (res < 0)
		{
			res += e->map.xlen;
		}
		res = res % e->map.xlen;
	}
	if (xy == 'Y')
	{
		while (res < 0)
		{
			res += e->map.ylen;
		}
		res = res % e->map.ylen;
	}
	return (res);
}

char					*lookoncase(t_env *e, int yc, int xc, int number)
{
	t_case				tmpc;
	char				*res;
	int					y;
	int					x;

	x = xc % e->map.xlen;
	y = yc % e->map.ylen;
	if (x < 0)
		x += e->map.xlen;
	if (y < 0)
		y += e->map.ylen;
	res = NULL;
	(void)number;
	tmpc = e->map.map[getrc(yc, 'Y', e)][getrc(xc, 'X', e)];
	x = 0;
	y = 0;
	res = get_case_ressource(tmpc, x, y, res);
	x = 0;
	return (lookoncase_(x, tmpc, res));
}
