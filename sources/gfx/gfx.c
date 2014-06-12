/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/12 18:16:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"
#include <unistd.h>
#include "gfx.h"

int	gfx_core(t_env *gfx)
{
	SDL_Event	ev;
	int			quit;

	quit = 0;
	while (!quit)
	{
		event_listener(&ev, &quit, gfx);
		SDL_RenderClear(gfx->e.render);
		move_camera(gfx);
		draw_board(gfx);
	}
	return (0);
}

int	gfx_net(t_env *gfx)
{
	int	sock;

	(void)gfx;
	if ((sock = create_client((char *)NULL, 0)) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	gfx;
	pid_t	pid;

	(void)argc;
	(void)argv;
	if (init_shm(&gfx) == 1)
		return (1);
	pid = fork();
	if (pid == 0)
		gfx_net(&gfx);
	else
	{
		ft_putendl("GFX on.");
		init_sdl(&gfx);
		gfx_core(&gfx);
		close_sdl(&gfx);
	}
	return (0);
}
