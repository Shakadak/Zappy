/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:31:38 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/26 18:36:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <signal.h>
#include <sys/socket.h>
#include <sys/mman.h>

int		allocate_map(t_env *gfx)
{
	char	**cmds;
	int		i;

	i = 0;
	cmds = (ft_strsplit(gfx->net.buff, '\n'));
	do_command(gfx, cmds[i++]);
	gfx->shm.shm->map = mmap(NULL, (gfx->msize[0] * gfx->msize[1]) * CASE_SIZE,
			PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	while (cmds[i])
		do_command(gfx, cmds[i++]);
	ft_split_destroy(cmds);
	ft_bzero(gfx->net.buff, READ_BUFF);
	gfx->shm.shm->time = -1;
	return (0);
}

int		get_map_info(t_env *gfx)
{
	int		ret;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = '\0';
	send(gfx->net.sock, "GRAPHIC\n", 8, 0);
	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = '\0';
	ft_putendl(gfx->net.buff);
	allocate_map(gfx);
	return (0);
}
