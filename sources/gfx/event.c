/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:51 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/11 17:34:18 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mouse_check_y(t_env *gfx, int y)
{
	if (y < 150)
	{
		gfx->dir = add_dir(gfx->dir, UP);
		gfx->s_speed = (150 - y) * 5 / 150;
	}
	else
		gfx->dir = rem_dir(gfx->dir, UP);
	if (y > (HEIGHT - 150))
	{
		gfx->dir = add_dir(gfx->dir, DOWN);
		gfx->s_speed = (150 - (HEIGHT - y)) * 5 / 150;
	}
	else
		gfx->dir = rem_dir(gfx->dir, DOWN);
}

void	mouse_check_x(t_env *gfx, int x)
{
	if (x < 150)
	{
		gfx->dir = add_dir(gfx->dir, LEFT);
		gfx->s_speed = (150 - x) * 5 / 150;
	}
	else
		gfx->dir = rem_dir(gfx->dir, LEFT);
	if (x > (WIDTH - 150))
	{
		gfx->dir = add_dir(gfx->dir, RIGHT);
		gfx->s_speed = (150 - (WIDTH - x)) * 5 / 150;
	}
	else
		gfx->dir = rem_dir(gfx->dir, RIGHT);
}

void	mouse_event(t_env *gfx)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	mouse_check_y(gfx, y);
	mouse_check_x(gfx, x);
}

int		is_clickable(t_env *gfx, int x, int y)
{
	(void)gfx;
	(void)x;
	(void)y;
	return (-1);
}

int		handle_click_event(t_env *gfx, int event)
{
	(void)gfx;
	(void)event;
	return (1);
}

void	click_event(t_env *gfx)
{
	int	x;
	int	y;
	int	event;

	(void)gfx;
	SDL_GetMouseState(&x, &y);
	if ((event = is_clickable(gfx, x, y)) >= 0)
		handle_click_event(gfx, event);
	printf("%d - %d\n", x, y);
}

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

int		event_listener(SDL_Event *ev, int *quit, t_env *gfx)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
		else if (ev->type == SDL_KEYDOWN || ev->type == SDL_KEYUP)
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
		else if (ev->type == SDL_MOUSEMOTION)
			mouse_event(gfx);
		else if (ev->type == SDL_MOUSEBUTTONDOWN)
			click_event(gfx);
	}
	return (0);
}
