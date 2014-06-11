/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/11 17:29:28 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfx.h"

void	draw_menu(t_env *gfx)
{
	SDL_Rect	rcdest;

	rcdest.x = 1620;
	rcdest.y = 0;
	rcdest.w = 300;
	rcdest.h = 1080;
	SDL_SetRenderDrawColor(gfx->e.render, 0x0E, 0x28, 0x49, 0xFF);
	SDL_RenderDrawRect(gfx->e.render, &rcdest);
}

void	draw_tiles(t_env *gfx)
{
	SDL_Rect	rc[2];
	int			minx;
	int			miny;
	int			maxx;
	int			maxy;

	rc[0].x = 0;
	rc[0].y = 200;
	rc[0].w = gfx->tile_w;
	rc[0].h = gfx->tile_h;
	rc[1].w = gfx->tile_w + gfx->zoom;
	rc[1].h = gfx->tile_h + gfx->zoom;
	minx = gfx->camera[0] / rc[1].w - 1;
	maxx = (gfx->camera[0] + WIDTH) / rc[1].w;
	maxy = (gfx->camera[1] + HEIGHT) / rc[1].h;
	while (minx <= maxx)
	{
		miny = gfx->camera[1] / rc[1].h - 1;
		while (miny <= maxy)
		{
			rc[1].x = minx * rc[1].w - gfx->camera[0];
			rc[1].y = miny * rc[1].h - gfx->camera[1];
			SDL_RenderCopy(gfx->e.render, gfx->e.tiles, &rc[0], &rc[1]);
			miny++;
		}
		minx++;
	}
}

void	draw_board(t_env *gfx)
{
	draw_tiles(gfx);
	SDL_RenderPresent(gfx->e.render);
}
