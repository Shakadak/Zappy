/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:01:31 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:01:34 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*dest;
	int		i;

	i = n - (int)ft_strlen(s2);
	dest = (char *)s1;
	if (!s2 || s2 == NULL)
		return (dest);
	else if (i < 0)
		return (NULL);
	if (!(ft_strncmp(dest, s2, n)))
		return (dest);
	while (*dest && i-- >= 0)
	{
		if (!(ft_memcmp(dest, s2, ft_strlen(s2))))
			return (dest);
		dest++;
	}
	return (NULL);
}
