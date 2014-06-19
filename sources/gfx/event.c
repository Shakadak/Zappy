/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:51 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/19 16:32:04 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int		zoom_in(t_env *gfx)
{
	if (gfx->zoom < 100)
		gfx->zoom++;
	return (0);
}

int		zoom_out(t_env *gfx)
{
	if (gfx->zoom > -gfx->tile_w / 2)
		gfx->zoom--;
	return (0);
}

void	switch_keys(t_env *gfx, SDL_Event *ev, int *quit)
{
	if (ev->key.keysym.sym == KEY_ESC)
		*quit = 1;
	else if (ev->key.keysym.sym == KEY_UP)
		gfx->dir = key_update(ev, gfx->dir, UP, gfx);
	else if (ev->key.keysym.sym == KEY_DOWN)
		gfx->dir = key_update(ev, gfx->dir, DOWN, gfx);
	else if (ev->key.keysym.sym == KEY_LEFT)
		gfx->dir = key_update(ev, gfx->dir, LEFT, gfx);
	else if (ev->key.keysym.sym == KEY_RIGHT)
		gfx->dir = key_update(ev, gfx->dir, RIGHT, gfx);
	else if (ev->key.keysym.sym == KEY_PLUS)
		zoom_in(gfx);
	else if (ev->key.keysym.sym == KEY_MINUS)
		zoom_out(gfx);
}

int		event_listener(SDL_Event *ev, int *quit, t_env *gfx)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
		else if (ev->type == SDL_KEYDOWN || ev->type == SDL_KEYUP)
			switch_keys(gfx, ev, quit);
		else if (ev->type == SDL_MOUSEMOTION)
			mouse_event(gfx);
		else if (ev->type == SDL_MOUSEBUTTONDOWN)
			click_event(gfx);
	}
	return (0);
}
