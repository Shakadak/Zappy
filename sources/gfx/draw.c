/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/07 16:23:30 by jvincent         ###   ########.fr       */
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
	SDL_Rect	rcsrc;
	SDL_Rect	rcdest;
	int			i;
	int			j;

	rcsrc.x = 0;
	rcsrc.y = 200;
	rcsrc.w = TILE_W;
	rcsrc.h = TILE_H;
	j = 0;
	while (j < MAP_Y)
	{
		i = 0;
		while (i < MAP_X)
		{
			rcdest.x = i * TILE_W;
			rcdest.y = j * TILE_H;
			rcdest.w = TILE_W;
			rcdest.h = TILE_H;
			SDL_RenderCopy(gfx->e.render, gfx->e.tiles, &rcsrc, &rcdest);
			i++;
		}
		j++;
	}
}

void	draw_board(t_env *gfx)
{
	SDL_Rect	rcdest;

	SDL_SetRenderTarget(gfx->e.render, gfx->e.board);
	SDL_RenderClear(gfx->e.render);
	draw_tiles(gfx);
	rcdest.x = gfx->camera[0];
	rcdest.y = gfx->camera[1];
	rcdest.w = MAP_W;
	rcdest.h = MAP_H;
	SDL_SetRenderTarget(gfx->e.render, NULL);
	SDL_RenderCopy(gfx->e.render, gfx->e.board, NULL, &rcdest);
}
