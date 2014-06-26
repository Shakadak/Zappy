/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 16:47:52 by npineau           #+#    #+#             */
/*   Updated: 2014/06/26 18:23:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	get_player_text(t_env *gfx, t_player *p, SDL_Rect *zone, int tick)
{
	int	x;

	(void)tick;
	x = 32;
	x = tick < 250 ? 0 : x;
	x = (500 <= tick && tick < 750) ? 64 : x;
	zone[0].x = x;
	zone[0].y = 0;
	zone[0].h = 72;
	zone[0].w = 32;
	zone[1].x = (p->x + 0.25) * (gfx->tile_w + gfx->zoom) - gfx->camera[W];
	zone[1].y = (p->y - 0.25) * (gfx->tile_h + gfx->zoom) - gfx->camera[H];
	zone[1].h = zone[0].h + gfx->zoom;
	zone[1].w = zone[0].w + gfx->zoom;
}

void	get_limit(t_env *gfx, SDL_Rect *limit)
{
	limit->x = gfx->camera[0] / gfx->tile_w - 1;
	limit->y = gfx->camera[1] / gfx->tile_h - 1;
	limit->w = (gfx->camera[0] + WIDTH) / (gfx->tile_w + gfx->zoom);
	limit->h = (gfx->camera[1] + HEIGHT) / (gfx->tile_h + gfx->zoom);
}

int		get_dir(int x, int y, int o)
{
	if (x)
	{
		if (o == NORTH || o == SOUTH)
			return (0);
		else if (o == EAST)
			return (1);
		else
			return (-1);
	}
	if (y)
	{
		if (o == EAST || o == WEST)
			return (0);
		else if (o == NORTH)
			return (1);
		else
			return (-1);
	}
	return (0);
}

void	draw_move(t_env *gfx, t_player *p)
{
	SDL_Rect		zone[2];
	unsigned int	tick;
	float			dist;
	SDL_Rect		limit;

	if ((tick = SDL_GetTicks()) >= p->time)
	{
		p->action = NONE;
		draw_player(gfx, p);
		return ;
	}
	dist = ((float)p->time - (float)tick) / (float)(7000 / gfx->shm.shm->time);
	get_player_text(gfx, p, zone, (tick / 2 + p->id * 10) % 1000);
	get_limit(gfx, &limit);
	if (p->x < limit.x || p->x > limit.w || p->y < limit.y || p->y > limit.h)
		return ;
	zone[1].x += get_dir(1, 0, p->dir) * ((gfx->tile_w + gfx->zoom) * dist);
	zone[1].y += get_dir(0, 1, p->dir) * ((gfx->tile_h + gfx->zoom) * dist);
	SDL_RenderCopy(gfx->e.render, gfx->e.player, &zone[0], &zone[1]);
}
