/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:54:47 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 12:47:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	bct(t_env *gfx, char **param)
{
	int		pos;
	t_case	*cell;

	pos = ft_atoi(param[1]) + gfx->msize[0] * ft_atoi(param[2]);
	cell = gfx->g->map[pos];
	cell->food = ft_atoi(param[3]);
	pos = 0;
	while (pos < 6)
	{
		cell->stones[pos] = ft_atoi(param[pos + 4]);
		pos++;
	}
}
