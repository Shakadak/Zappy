/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:54:06 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/19 16:28:41 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/mman.h>
#include "gfx.h"

SDL_Texture	*load_texture(t_env *gfx, char *str)
{
	SDL_Texture	*texture;
	SDL_Surface	*image;

	texture = NULL;
	image = IMG_Load(str);
	texture = SDL_CreateTextureFromSurface(gfx->e.render, image);
	SDL_FreeSurface(image);
	return (texture);
}

int			init_tiles(t_env *gfx)
{
	gfx->e.tiles = load_texture(gfx, "img/tiles.png");
	return (0);
}

int			init_sdl(t_env *gfx)
{
	int	img_flag;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_error("SDL_Init failed."));
	gfx->e.win = SDL_CreateWindow("ZAPPY", SDL_WPU, SDL_WPU, WIDTH, HEIGHT, FS);
	if (gfx->e.win == NULL)
		return (ft_error("Can't create window."));
	gfx->e.render = SDL_CreateRenderer(gfx->e.win, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(gfx->e.render, 0xCE, 0xCE, 0xCE, 0xFF);
	img_flag = IMG_INIT_PNG;
	IMG_Init(img_flag);
	init_tiles(gfx);
	gfx->camera[0] = 0;
	gfx->camera[1] = 0;
	gfx->s_speed = 1;
	gfx->zoom = 1;
	gfx->tile_w = 40;
	gfx->tile_h = 40;
	gfx->dir = 0;
	return (0);
}

void		close_sdl(t_env *gfx)
{
	kill(gfx->net_pid, SIGTERM);
	munmap(gfx->shm.shm->map, (gfx->msize[0] * gfx->msize[1]) * sizeof(t_case));
	shm_free(gfx);
	SDL_DestroyTexture(gfx->e.tiles);
	SDL_DestroyRenderer(gfx->e.render);
	SDL_DestroyWindow(gfx->e.win);
	SDL_Quit();
}
