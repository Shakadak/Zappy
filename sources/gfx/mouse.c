/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:18:27 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/13 16:27:36 by jvincent         ###   ########.fr       */
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
