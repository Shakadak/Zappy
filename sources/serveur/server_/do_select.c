/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:16:25 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:16:27 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bircd.h"

void	do_select(t_env *e)
{
	struct timeval	test;

	test.tv_sec = 12 / e->time_unit;
	e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, &test);
}
