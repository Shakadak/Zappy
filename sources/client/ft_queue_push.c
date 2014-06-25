/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 03:11:03 by garm              #+#    #+#             */
/*   Updated: 2014/06/25 00:34:43 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_queue		*ft_queue_push(t_queue *q, void *data)
{
	t_queue		*new;

	new = ft_queue_create(data);
	if (!new)
		return (NULL);
	if (q)
	{
		q->tail->next = new;
		q->tail = new;
	}
	else
	{
		q = new;
		q->tail = q;
	}
	return (q);
}
