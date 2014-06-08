/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:17 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/08 18:59:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	move_camera(t_env *gfx)
{
	if ((gfx->dir & UP) && gfx->camera[1] + gfx->s_speed < 0)
		gfx->camera[1] += gfx->s_speed;
	if ((gfx->dir & DOWN) && gfx->camera[1] > -(MAP_H - HEIGHT - gfx->s_speed))
		gfx->camera[1] -= gfx->s_speed;
	if ((gfx->dir & LEFT) && gfx->camera[0] + gfx->s_speed < 0)
		gfx->camera[0] += gfx->s_speed;
	if ((gfx->dir & RIGHT) && gfx->camera[0] > -(MAP_W - WIDTH - gfx->s_speed))
		gfx->camera[0] -= gfx->s_speed;
}
