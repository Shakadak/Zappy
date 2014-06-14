/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:15:15 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:15:17 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*p;

	if (n && s)
	{
		p = s;
		while (n--)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
		}
	}
	return (0);
}
