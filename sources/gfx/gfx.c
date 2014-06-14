/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/14 21:04:48 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/mman.h>
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

int	allocate_map(t_env *gfx)
{
	/* mmap the board ! */
	/* get map x and y */
	/* while i < x * y */
	/*    get_cell */
	/* get_teams */
	/* launch SDL  */
	char	**cmd;
	int		x;
	int		y;

	cmd = ft_strsplit(gfx->net.buff, ' ');
	x = ft_atoi(cmd[1]);
	y = ft_atoi(cmd[2]);
	gfx->g->map = mmap(NULL, (x * y) * sizeof(t_case), PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANON, -1, 0);
	printf("%d - %d\n", x, y);
	gfx->msize[0] = x;
	gfx->msize[1] = y;
	ft_split_destroy(cmd);
	return (0);
}

int	get_map_info(t_env *gfx)
{
	int		ret;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = '\0';
	printf("[SERVER] : %s\n", gfx->net.buff);
	send(gfx->net.sock, "GRAPHIC\n", 8, 0);
	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = '\0';
	printf("[SERVER] : %s\n", gfx->net.buff);
	allocate_map(gfx);
	return (0);
}

int	gfx_net(t_env *gfx)
{
	if ((gfx->net.sock = create_client(gfx->net.ip, gfx->net.port, gfx)) == -1)
		return (-1);
	get_map_info(gfx);
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
	gfx.net.ip = argv[1];
	gfx.net.port = ft_atoi(argv[2]);
	gfx_net(&gfx);
	if (init_shm(&gfx, sizeof(t_game)) == 1)
		return (1);
	pid = fork();
	if (pid == 0)
		gfx_net_loop(&gfx);
	else
	{
		gfx.net_pid = pid;
		ft_putendl("GFX on.");
		init_sdl(&gfx);
		gfx_core(&gfx);
		close_sdl(&gfx);
	}
	return (0);
}
