/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:09:38 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/21 15:09:59 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (!size)
		return (NULL);
	if ((res = malloc (size)))
	{
		ft_bzero(res, size);
		return (res);
	}
	else
		return (NULL);
}
