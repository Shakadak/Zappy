/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:17 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/07 16:21:51 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	move_camera(t_env *gfx)
{
	if (gfx->scroll[0] && gfx->camera[1] + gfx->s_speed < 0)
		gfx->camera[1] += gfx->s_speed;
	if (gfx->scroll[1] && gfx->camera[1] > -(MAP_H - HEIGHT - gfx->s_speed))
		gfx->camera[1] -= gfx->s_speed;
	if (gfx->scroll[2] && gfx->camera[0] + gfx->s_speed < 0)
		gfx->camera[0] += gfx->s_speed;
	if (gfx->scroll[3] && gfx->camera[0] > -(MAP_W - WIDTH - gfx->s_speed))
		gfx->camera[0] -= gfx->s_speed;
}
