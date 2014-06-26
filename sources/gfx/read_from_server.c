/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:49:28 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/26 18:36:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "gfx.h"

void		do_command(t_env *gfx, char *cmd)
{
	char	**split;
	void	(*func)();

	split = ft_strsplit(cmd, ' ');
	func = get_x(split[0]);
	if (func)
		func(gfx, split);
	ft_split_destroy(split);
}

void		read_from_server(t_env *gfx)
{
	int		ret;
	char	**cmds;
	int		i;

	i = 0;
	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = 0;
	ft_putendl(gfx->net.buff);
	cmds = (ft_strsplit(gfx->net.buff, '\n'));
	while (cmds[i])
		do_command(gfx, cmds[i++]);
	ft_split_destroy(cmds);
	if (gfx->shm.shm->time == -1)
		send(gfx->net.sock, "sgt\n", 4, 0);
	ft_bzero(gfx->net.buff, READ_BUFF);
}
