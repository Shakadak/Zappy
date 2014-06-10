/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/10 19:13:49 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			i;
	int			j;

	rc[0].x = 0;
	rc[0].y = 200;
	rc[0].w = TILE_W;
	rc[0].h = TILE_H;
	rc[1].w = TILE_W;
	rc[1].h = TILE_H;
	j = gfx->camera[0];
	while (j < MAP_Y)
	{
		i = gfx->camera[1];
		rc[1].y = j * TILE_H;
		while (i < MAP_X)
		{
			rc[1].x = i * TILE_W;
			SDL_RenderCopy(gfx->e.render, gfx->e.tiles, &rc[0], &rc[1]);
			i++;
		}
		j++;
	}
}

void	draw_board(t_env *gfx)
{
	SDL_Rect	rcdest;
	static int	first = 0;

	if (!first)
	{
		SDL_SetRenderTarget(gfx->e.render, gfx->e.board);
		SDL_RenderClear(gfx->e.render);
		draw_tiles(gfx);
		first = 1;
	}
	rcdest.x = gfx->camera[0];
	rcdest.y = gfx->camera[1];
	rcdest.w = MAP_W;
	rcdest.h = MAP_H;
	SDL_SetRenderTarget(gfx->e.render, NULL);
	SDL_RenderCopy(gfx->e.render, gfx->e.board, NULL, &rcdest);
}
