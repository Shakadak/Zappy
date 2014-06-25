/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:07:51 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:38:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pgt(t_env *gfx, char **param)
{
	t_player	*current;
	t_case		*cell;

	if (ft_arrlen((void **)param) != 3)
		return ;
	current = get_player(gfx, ft_atoi(param[1]), 0, PLAYER);
	cell = gfx->shm.shm->map + (current->x + current->y * gfx->msize[1]);
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
