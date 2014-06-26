/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:49:28 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/26 14:06:50 by npineau          ###   ########.fr       */
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

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = 0;
	do_command(gfx, gfx->net.buff);
	ft_bzero(gfx->net.buff, READ_BUFF);
}
