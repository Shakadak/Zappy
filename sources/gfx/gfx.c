/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/13 18:28:26 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"
#include <unistd.h>
#include "gfx.h"
#include "libft.h"

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
		SDL_RenderPresent(gfx->e.render);
	}
	return (0);
}

int	gfx_net(t_env *gfx)
{
	if ((gfx->net.sock = create_client(gfx->net.ip, gfx->net.port)) == -1)
		return (-1);
	gfx_net_loop(gfx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	gfx;
	pid_t	pid;

	if (argc != 3)
	{
		ft_putendl("usage: ./gfx <ip> <port>");
		return (1);
	}
	if (init_shm(&gfx, SHM_SIZE) == 1)
		return (1);
	gfx.net.ip = argv[1];
	gfx.net.port = ft_atoi(argv[2]);
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
