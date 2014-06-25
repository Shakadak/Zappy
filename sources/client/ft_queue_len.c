/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 06:44:58 by garm              #+#    #+#             */
/*   Updated: 2014/06/25 06:45:45 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_queue_len(t_queue *q)
{
	int		i;

	i = 0;
	while (q)
	{
		q = q->next;
		i++;
	}
	return (i);
}
