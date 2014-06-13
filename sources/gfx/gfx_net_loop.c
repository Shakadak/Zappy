/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_net_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 17:40:36 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/13 18:58:16 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void		init_loop(t_env *gfx)
{
	FD_ZERO(&gfx->net.readfds);
	FD_SET(gfx->net.sock, &gfx->net.readfds);
}

static void		check_server(t_env *gfx)
{
	if (FD_ISSET(gfx->net.sock, &gfx->net.readfds))
		read_from_server(gfx);
}

int				gfx_net_loop(t_env *gfx)
{
	while (1)
	{
		init_loop(gfx);
		select(gfx->net.sock + 1, &gfx->net.readfds, 0, 0, 0);
		check_server(gfx);
	}
	return (0);
}
