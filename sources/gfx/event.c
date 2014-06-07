/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:51 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/07 16:12:57 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mouse_check_y(t_env *gfx, int y)
{	
	if (y < 150)
	{
		gfx->scroll[0] = 1;
		gfx->s_speed = (150 - y) * 5 / 150;
	}
	else
		gfx->scroll[0] = 0;
	if (y > (HEIGHT - 150))
	{
		gfx->scroll[1] = 1;
		gfx->s_speed = (150 - (HEIGHT - y)) * 5 / 150;
	}
	else
		gfx->scroll[1] = 0;
}

void	mouse_check_x(t_env *gfx, int x)
{
	if (x < 150)
	{
		gfx->scroll[2] = 1;
		gfx->s_speed = (150 - x) * 5 / 150;
	}
	else
		gfx->scroll[2] = 0;
	if (x > (WIDTH - 150))
	{
		gfx->scroll[3] = 1;
		gfx->s_speed = (150 - (WIDTH - x)) * 5 / 150;
	}
	else
		gfx->scroll[3] = 0;
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

int	event_listener(SDL_Event *ev, int *quit, t_env *gfx)
{
	while (SDL_PollEvent(ev) != 0)
	{
		if (ev->type == SDL_QUIT)
			*quit = 1;
		else if (ev->type == SDL_KEYDOWN)
		{
			if (ev->key.keysym.sym == KEY_ESC)
				*quit = 1;
			else if (ev->key.keysym.sym == KEY_UP)
				gfx->camera[1] -= 1;
			else if (ev->key.keysym.sym == KEY_DOWN)
				gfx->camera[1] += 1;
			else if (ev->key.keysym.sym == KEY_LEFT)
				gfx->camera[0] -= 1;
			else if (ev->key.keysym.sym == KEY_RIGHT)
				gfx->camera[0] += 1;
		}
		else if (ev->type == SDL_MOUSEMOTION)
			mouse_event(gfx);
		else if (ev->type == SDL_MOUSEBUTTONDOWN)
			click_event(gfx);
	}
	return (0);
}
