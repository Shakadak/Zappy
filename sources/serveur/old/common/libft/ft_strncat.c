/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:00:26 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:00:33 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	srci;
	char	*tmp;

	index = ft_strlen(dest);
	srci = 0;
	tmp = dest;
	if (!src || !n)
		return (dest);
	while ((src[srci] != '\0') && (srci < n))
	{
		tmp[index] = (char)src[srci];
		index = index + 1;
		srci = srci + 1;
	}
	dest[index] = '\0';
	return (dest);
}
