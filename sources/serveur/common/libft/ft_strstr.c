/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:01:18 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:01:20 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len;

	len = ft_strlen((char *)s2);
	dest = (char *)s1;
	if (s2[0] == 0)
		return (dest);
	while (*dest)
	{
		if (!ft_memcmp(dest, s2, len))
			return (dest);
		dest++;
	}
	return (NULL);
}
