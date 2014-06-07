/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:39 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/07 16:16:24 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	draw_menu(t_env *gfx)
{
	SDL_Rect	rcDest;

	rcDest.x = 1620;
	rcDest.y = 0;
	rcDest.w = 300;
	rcDest.h = 1080;
	SDL_SetRenderDrawColor(gfx->e.render, 0x0E, 0x28, 0x49, 0xFF);
	SDL_RenderDrawRect(gfx->e.render, &rcDest);
}

void	draw_tiles(t_env *gfx)
{
	SDL_Rect	rcSrc;
	SDL_Rect	rcDest;
	int			i;
	int			j;
	
	rcSrc.x = 0;
	rcSrc.y = 200;
	rcSrc.w = TILE_W;
	rcSrc.h = TILE_H;
	j = 0;
	while (j < MAP_Y)
	{
		i = 0;
		while (i < MAP_X)
		{
			rcDest.x = i * TILE_W;
			rcDest.y = j * TILE_H;
			rcDest.w = TILE_W;
			rcDest.h = TILE_H;
			SDL_RenderCopy(gfx->e.render, gfx->e.tiles, &rcSrc, &rcDest);
			i++;
		}
		j++;
	}
}

void	draw_board(t_env *gfx)
{
	SDL_Rect	rcDest;

	SDL_SetRenderTarget(gfx->e.render, gfx->e.board);
	SDL_RenderClear(gfx->e.render);
	draw_tiles(gfx);
	rcDest.x = gfx->camera[0];
	rcDest.y = gfx->camera[1];
	rcDest.w = MAP_W;
	rcDest.h = MAP_H;
	SDL_SetRenderTarget(gfx->e.render, NULL);
	SDL_RenderCopy(gfx->e.render, gfx->e.board, NULL, &rcDest);
}
