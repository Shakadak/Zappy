/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_none.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:25:49 by npineau           #+#    #+#             */
/*   Updated: 2014/06/23 15:38:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	draw_none(t_env *gfx, t_player *p)
{
	SDL_Rect		zone[2];
	unsigned int	tick;
	SDL_Rect		limit;

	tick = SDL_GetTicks();
	get_player_text(gfx, p, zone, tick % 1000);
	get_limit(gfx, &limit);
	if (p->x < limit.x || p->x > limit.w || p->y < limit.y || p->y > limit.h)
		return ;
	SDL_RenderCopy(gfx->e.render, gfx->e.player, &zone[0], &zone[1]);
}
