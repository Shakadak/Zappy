/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_do_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:14 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 18:12:31 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"

void	do_select(t_env *e)
{
	e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
}
