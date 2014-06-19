/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:31:38 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/19 15:17:11 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <signal.h>
#include <sys/socket.h>
#include <sys/mman.h>

void	get_cell_info(t_env *gfx)
{
	char	**cmd;
	int		ret;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	printf("Le serveur dit : %s\n", gfx->net.buff);
	cmd = ft_strsplit(gfx->net.buff, ' ');
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
	ft_split_destroy(cmd);
	return (0);
}

int		allocate_map(t_env *gfx)
{
	char	**cmd;

	cmd = ft_strsplit(gfx->net.buff, ' ');
	msz(gfx, cmd);
	gfx->shm.shm->map = mmap(NULL, (gfx->msize[0] * gfx->msize[1]) * CASE_SIZE,
			PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	ft_split_destroy(cmd);
	fill_cells(gfx);
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
