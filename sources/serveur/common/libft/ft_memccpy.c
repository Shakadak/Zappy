/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:21:26 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:21:28 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t		index;
	char		*d2;
	char		*s2;

	index = 0;
	d2 = (char *)d;
	s2 = (char *)s;
	if (!s)
		return (NULL);
	while (index < n)
	{
		if ((char)s2[index] == c)
		{
			d2[index] = (char)s2[index];
			return (&d2[index + 1]);
		}
		d2[index] = (char)s2[index];
		index++;
	}
	return (NULL);
}
