/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:31:09 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 14:38:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "serveur.h"
#include "libft.h"

void	client_write(t_env *e, int cs)
{
	int	len;

	len = e->fds[cs].fw;
	if (len)
	{
		send(cs, e->fds[cs].buf_write, len, 0);
		e->fds[cs].fw = 0;
		ft_bzero(e->fds[cs].buf_write, BUF_SIZE);
	}
}
