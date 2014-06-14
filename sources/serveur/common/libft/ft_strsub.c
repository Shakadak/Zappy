/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:06:47 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:06:49 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strsub(char const *s,
						unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		l;
	char				*dest;

	i = start;
	l = 0;
	if (!s || s == NULL || len == 0)
		return (NULL);
	if (strlen(s) < start)
		return (NULL);
	dest = malloc(sizeof(char) * ((len) + 1));
	while (len > 0 && (char)s[i] != '\0')
	{
		dest[l] = (char)s[i];
		dest[l + 1] = '\0';
		len--;
		i++;
		l++;
	}
	return (dest);
}
