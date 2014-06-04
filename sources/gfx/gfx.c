/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/04 17:54:02 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int	gfx_core(t_env *gfx)
{
	SDL_Event	ev;
	int			quit;

	quit = 0;
	while (!quit)
	{
		event_listener(&ev, &quit, gfx);
		SDL_RenderClear(gfx->e.screen);
		move_camera(gfx);
		draw_board(gfx);
		SDL_RenderPresent(gfx->e.screen);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	gfx;
	
	(void)argc;
	(void)argv;

	ft_putendl("GFX on.");
	init_sdl(&gfx);
	gfx_core(&gfx);
	close_sdl(&gfx);
	return (0);
}
