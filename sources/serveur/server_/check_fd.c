/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:13:03 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:13:04 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

void	check_fd(t_env *e)
{
	int	i;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
			e->fds[i].fct_read(e, i);
		if (FD_ISSET(i, &e->fd_write))
			e->fds[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read) ||
				FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}
