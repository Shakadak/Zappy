/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:17 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/11 17:29:56 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	move_camera(t_env *gfx)
{
	gfx->map_w = (gfx->tile_w + gfx->zoom) * MAP_X;
	gfx->map_h = (gfx->tile_h + gfx->zoom) * MAP_Y;
	if ((gfx->dir & UP) && gfx->camera[1] > 0)
		gfx->camera[1] -= gfx->s_speed;
	if ((gfx->dir & DOWN) && gfx->camera[1] < (gfx->map_h - HEIGHT))
		gfx->camera[1] += gfx->s_speed;
	if ((gfx->dir & LEFT) && gfx->camera[0] > 0)
		gfx->camera[0] -= gfx->s_speed;
	if ((gfx->dir & RIGHT) && gfx->camera[0] < (gfx->map_w - WIDTH))
		gfx->camera[0] += gfx->s_speed;
}
