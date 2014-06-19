/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 18:18:15 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/19 16:08:46 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

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
	int	xcase, ycase;
	xcase = (gfx->camera[0] + x) / gfx->tile_w;
	ycase = (gfx->camera[1] + y) / gfx->tile_h;
	printf("%d - %d\n", xcase, ycase);
}
