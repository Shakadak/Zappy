/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_net.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/13 16:47:39 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/13 18:43:41 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_NET_H
# define GFX_NET_H

#include "gfx_struct.h"

int		x_int(int err, int res, char *str, t_env *gfx);
void	*x_void(void *err, void *res, char *str, t_env *gfx);

int		create_client(char *addr, int port, t_env *gfx);
int		gfx_net_loop(t_env *gfx);
void	read_from_server(t_env *gfx);

#endif
