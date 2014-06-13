/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:14:59 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:15:00 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		index;
	char		*c1;
	char		*c2;

	index = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	if (!s2)
		return (NULL);
	while (index < n)
	{
		c1[index] = c2[index];
		index = index + 1;
	}
	return ((char *)s1);
}
