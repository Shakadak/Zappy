/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ban_neg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 01:54:48 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:25:42 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

int		ft_ban_neg(int n)
{
	if (n < 0)
		n = 0;
	return (n);
}
