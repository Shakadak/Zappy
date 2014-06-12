/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx-net.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:09:43 by npineau           #+#    #+#             */
/*   Updated: 2014/06/12 18:13:58 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_NET_H
# define GFX_NET_H

int		x_int(int err, int res, char *str);
void	*x_void(void *err, void *res, char *str);

int	create_client(char *addr, int port);

#endif
