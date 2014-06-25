/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 03:08:31 by garm              #+#    #+#             */
/*   Updated: 2014/06/25 00:34:31 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_queue		*ft_queue_create(void *data)
{
	t_queue		*q;

	q = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->data = data;
	q->next = NULL;
	q->tail = NULL;
	return (q);
}
