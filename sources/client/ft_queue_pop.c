/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 03:23:23 by garm              #+#    #+#             */
/*   Updated: 2014/06/25 00:34:35 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		*ft_queue_pop(t_queue **q)
{
	void		*data;
	t_queue		*todel;

	if (!q || !*q)
		return (NULL);
	todel = *q;
	if (todel->next)
	{
		(*q) = (*q)->next;
		(*q)->tail = todel->tail;
	}
	else
		*q = NULL;
	data = todel->data;
	ft_memdel((void **)&todel);
	return (data);
}
