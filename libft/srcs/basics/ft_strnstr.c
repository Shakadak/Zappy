/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:23:57 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 11:20:23 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;
	size_t		len_s2;
	
	if (!s1 || !s2)
		return (NULL);
	if (*s1 == 0 && *s1 == *s2)
		return ((char *)s1);
	if (!*s1 || !*s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (s1 && i < len && i < n)
	{
		if (n - i < len_s2)
			return (NULL);
		if (ft_memcmp(&s1[i], s2, len_s2) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
