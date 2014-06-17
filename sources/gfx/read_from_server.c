/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:49:28 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/17 15:33:18 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "gfx.h"

void		read_from_server(t_env *gfx)
{
	int		ret;
	char	**split;
	void	(*func)();

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = 0;
	split = ft_strsplit(gfx->net.buff, ' ');
	func = get_x(split[0]);
	func(gfx, split);
	ft_split_destroy(split);
	ft_bzero(gfx->net.buff, READ_BUFF);
}
