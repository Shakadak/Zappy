/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:17:54 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/16 18:39:59 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include "gfx.h"
#include "libft.h"

int		gfx_core(t_env *gfx)
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

void	get_cell_info(t_env *gfx)
{
	char	**cmd;
	int		ret;
	int		x;
	int		y;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	printf("Le serveur dit : %s\n", gfx->net.buff);
	cmd = ft_strsplit(gfx->net.buff, ' ');
/*	x = ft_atoi(cmd[1]);
	y = ft_atoi(cmd[2]);
	gfx->g->map[y * gfx->msize[0] + x].stones[0] = ft_atoi(cmd[3]);
	gfx->g->map[y * gfx->msize[0] + x].stones[1] = ft_atoi(cmd[4]);
	gfx->g->map[y * gfx->msize[0] + x].stones[2] = ft_atoi(cmd[5]);
	gfx->g->map[y * gfx->msize[0] + x].stones[3] = ft_atoi(cmd[6]);
	gfx->g->map[y * gfx->msize[0] + x].stones[4] = ft_atoi(cmd[7]);
	gfx->g->map[y * gfx->msize[0] + x].stones[5] = ft_atoi(cmd[8]);
	gfx->g->map[y * gfx->msize[0] + x].food = ft_atoi(cmd[9]);
*/
	bct(gfx, cmd);
	ft_split_destroy(cmd);
}

int		fill_cells(t_env *gfx)
{
	int	i;
	int	j;

	j = 0;
	while (j < gfx->msize[1])
	{
		i = 0;
		while (i < gfx->msize[0])
		{
			get_cell_info(gfx);
			i++;
		}
		j++;
	}
	return (0);
}

int		get_teams(t_env *gfx)
{
	char	**cmd;
	int		ret;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	cmd = ft_strsplit(gfx->net.buff, ' ');
	/*
	 * end this crap
	*/
	ft_split_destroy(cmd);
	return (0);
}

int		allocate_map(t_env *gfx)
{
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
	fill_cells(gfx);
/*	get_teams(gfx);*/
	return (0);
}

int		get_map_info(t_env *gfx)
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

int		gfx_net(t_env *gfx)
{
	if ((gfx->net.sock = create_client(gfx->net.ip, gfx->net.port, gfx)) == -1)
		return (-1);
	get_map_info(gfx);
	return (0);
}

int		main(int argc, char **argv)
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
