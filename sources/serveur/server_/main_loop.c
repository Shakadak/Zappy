/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:17:10 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:17:11 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

void		aff_map_(int x, int y, char **toaff, t_env *e)
{
	char	c;
	int		i;

	i = -1;
	while (++i < e->nbpl)
	{
		if (e->pl[i].alive)
			toaff[e->pl[i].y][e->pl[i].x] = e->pl[i].dir + '0';
	}
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

void		aff_map(t_env *e)
{
	char	**toaff;
	int		x;
	int		y;

	x = 0;
	y = 0;
	toaff = (char **)malloc(sizeof(char *) * e->map.ylen);
	while (y < e->map.ylen)
	{
		toaff[y] = (char *)malloc(sizeof(char) * e->map.xlen);
		while (x < e->map.xlen)
		{
			toaff[y][x] = '-';
			toaff[y][x + 1] = '\0';
			x++;
		}
		toaff[y + 1] = '\0';
		x = 0;
		y++;
	}
	ft_putstr("\n");
	aff_map_(x, y, toaff, e);
	sstrmemdel(&toaff);
	ft_putstr("\n");
	return ;
}

void		main_loop(t_env *e)
{
	int		i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < e->nbteam)
			i++;
		init_fd(e);
		do_select(e);
		check_fd(e);
		serv_update(e);
	}
}
