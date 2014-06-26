/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/26 19:55:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfx.h"

void	render_stone(t_env *gfx, int i, SDL_Rect tile)
{
	SDL_Rect	rcsrc;

	rcsrc.w = 8;
	rcsrc.h = 8;
	rcsrc.x = i * 8;
	rcsrc.y = 0;
	tile.w = 8 + gfx->zoom;
	tile.h = 8 + gfx->zoom;
	tile.x += 3 * i % gfx->tile_w;
	tile.y += 4 * i % gfx->tile_h;
	SDL_RenderCopy(gfx->e.render, gfx->e.stones, &rcsrc, &tile);
}

void	draw_stones(t_env *gfx, int x, int y, SDL_Rect tile)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (gfx->shm.shm->map[y * gfx->msize[0] + x].stones[i] != 0)
			render_stone(gfx, i, tile);
		i++;
	}
}

void	draw_tile(t_env *gfx, SDL_Rect rc[2], int x, int y)
{
	x = (x < 0 ? 0 : x);
	y = (y < 0 ? 0 : y);
	SDL_RenderCopy(gfx->e.render, gfx->e.tiles, &rc[0], &rc[1]);
	draw_stones(gfx, x, y, rc[1]);
}

void	draw_tiles(t_env *gfx)
{
	SDL_Rect	rc[2];
	int			min[2];
	int			max[2];

	rc[0].x = 0;
	rc[0].y = 0;
	rc[0].w = 64;
	rc[0].h = 64;
	rc[1].w = gfx->tile_w + gfx->zoom;
	rc[1].h = gfx->tile_h + gfx->zoom;
	min[0] = (gfx->camera[0] - (gfx->tile_w - 1)) / gfx->tile_w;
	max[0] = (gfx->camera[0] + WIDTH) / rc[1].w;
	max[1] = (gfx->camera[1] + HEIGHT) / rc[1].h;
	while (min[0] <= max[0] && min[0] < gfx->msize[0])
	{
		min[1] = (gfx->camera[1] - (gfx->tile_h - 1)) / gfx->tile_h;
		while (min[1] <= max[1] && min[1] < gfx->msize[1])
		{
			rc[1].x = min[0] * rc[1].w - gfx->camera[0];
			rc[1].y = min[1] * rc[1].h - gfx->camera[1];
			draw_tile(gfx, rc, min[0], min[1]);
			min[1]++;
		}
		min[0]++;
	}
}

void	draw_board(t_env *gfx)
{
	draw_tiles(gfx);
	draw_entity(gfx);
}
