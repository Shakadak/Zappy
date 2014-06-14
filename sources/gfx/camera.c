/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:17 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/14 21:48:38 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	move_camera(t_env *gfx)
{
	gfx->map_w = (gfx->tile_w + gfx->zoom) * gfx->msize[0];
	gfx->map_h = (gfx->tile_h + gfx->zoom) * gfx->msize[1];
	if ((gfx->dir & UP) && gfx->camera[1] > 0)
		gfx->camera[1] -= gfx->s_speed;
	if ((gfx->dir & DOWN) && gfx->camera[1] < (gfx->map_h - HEIGHT))
		gfx->camera[1] += gfx->s_speed;
	if ((gfx->dir & LEFT) && gfx->camera[0] > 0)
		gfx->camera[0] -= gfx->s_speed;
	if ((gfx->dir & RIGHT) && gfx->camera[0] < (gfx->map_w - WIDTH))
		gfx->camera[0] += gfx->s_speed;
}
