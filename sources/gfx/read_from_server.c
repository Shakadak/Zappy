/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:49:28 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/14 21:22:32 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "gfx.h"

void		read_from_server(t_env *gfx)
{
	int		ret;

	ret = recv(gfx->net.sock, gfx->net.buff, READ_BUFF, 0);
	gfx->net.buff[ret] = 0;
	//PARSING HERE
	ft_bzero(gfx->net.buff, READ_BUFF);
}
