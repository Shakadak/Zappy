/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_update.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:02:45 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:02:46 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bircd.h"

void		g_send_pl(t_pl pl, int i, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("ppo #");
		tmp = ft_straddrp(tmp, ft_itoa(i));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_straddrp(tmp, ft_itoa(pl.x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_straddrp(tmp, ft_itoa(pl.y));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_straddrp(tmp, ft_itoa(pl.dir));
		tmp = ft_stradd(tmp, "\n");
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void		g_send_case(t_case c, int x, int y, t_env *e)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("bct ");
		tmp = ft_straddrp(tmp, ft_itoa(x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_straddrp(tmp, ft_itoa(y));
		i = -1;
		while (++i < NBRESSOURCE)
		{
			tmp = ft_stradd(tmp, " ");
			tmp = ft_straddrp(tmp, ft_itoa(c.r[i]));
		}
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void		g_send_map(t_env *e)
{
	int		j;
	int		i;

	i = -1;
	j = -1;
	while (++i < e->map.ylen)
	{
		while (++j < e->map.xlen)
			g_send_case(e->map.map[i][j], j, i, e);
		j = -1;
	}
	return ;
}

void		g_send_egg(t_egg egg, int pl, int eggnb, t_env *e)
{
	char	*res;

	if (!egg.used)
	{
		res = ft_strclone("enw #");
		res = ft_straddrp(res, ft_itoa(eggnb));
		res = ft_stradd(res, " #");
		res = ft_straddrp(res, ft_itoa(pl));
		res = ft_stradd(res, " ");
		res = ft_straddrp(res, ft_itoa(egg.x));
		res = ft_stradd(res, " ");
		res = ft_straddrp(res, ft_itoa(egg.y));
		send_res(-1, res, e);
		res = NULL;
		free(res);
	}
	return ;
}
