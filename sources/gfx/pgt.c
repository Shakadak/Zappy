/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:07:51 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 17:10:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pgt(t_env *gfx, char **param)
{
	t_player	*current;
	t_case		*cell;

	current = get_player(gfx, ft_atoi(param[1]), 0, PLAYER);
	cell = gfx->g->map + (current->x + current->y * gfx->msize[1]);
	if (ft_atoi(param[2]) == 0)
	{
		current->food++;
		cell->food--;
	}
	else
	{
		current->stones[ft_atoi(param[2]) - 1]++;
		cell->stones[ft_atoi(param[2]) - 1]--;
	}
}
