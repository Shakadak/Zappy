/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:28:33 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:28:39 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_raw_init(t_raw *raw, int range_start, int center, int range_end)
{
	raw->range_start = range_start;
	raw->center = center;
	raw->range_end = range_end;
}

void	ft_vision_init(t_env *e)
{
	ft_raw_init(&e->vision[0], 1, 2, 3);
	ft_raw_init(&e->vision[1], 4, 6, 8);
	ft_raw_init(&e->vision[2], 9, 12, 15);
	ft_raw_init(&e->vision[3], 16, 20, 24);
	ft_raw_init(&e->vision[4], 25, 30, 35);
	ft_raw_init(&e->vision[5], 36, 42, 48);
	ft_raw_init(&e->vision[6], 49, 56, 63);
	ft_raw_init(&e->vision[7], 64, 72, 80);
}

void	ft_inventory_init(t_env *e)
{
	ft_bzero(&e->inventory, sizeof(t_inventory));
	e->inventory.life = 10;
}

void	ft_step_init(t_env *e, int level, const char *format)
{
	char		**split;

	split = ft_strsplit(format, ' ');
	e->steps[level].needed_players = ft_atoi(split[0]);
	e->steps[level].needed_stones.linemate = ft_atoi(split[1]);
	e->steps[level].needed_stones.deraumere = ft_atoi(split[2]);
	e->steps[level].needed_stones.sibure = ft_atoi(split[3]);
	e->steps[level].needed_stones.mendiane = ft_atoi(split[4]);
	e->steps[level].needed_stones.phiras = ft_atoi(split[5]);
	e->steps[level].needed_stones.thystame = ft_atoi(split[6]);
	ft_split_destroy(split);
}

void	ft_steps_init(t_env *e)
{
	ft_step_init(e, 1, "1 1 0 0 0 0 0");
	ft_step_init(e, 2, "2 1 1 1 0 0 0");
	ft_step_init(e, 3, "2 2 0 1 0 2 0");
	ft_step_init(e, 4, "4 1 1 2 0 1 0");
	ft_step_init(e, 5, "4 1 2 1 3 0 0");
	ft_step_init(e, 6, "6 1 2 3 0 1 0");
	ft_step_init(e, 7, "6 2 2 2 2 2 1");
}
