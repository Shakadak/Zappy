/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:01:02 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:01:03 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*res;

	len = 0;
	if (!s || s == NULL)
		return (NULL);
	res = NULL;
	while (s[len] != '\0')
	{
		if (s[len] == c)
			res = (char *)&s[len];
		len++;
	}
	if (c == 0 && s[len] == '\0')
		res = (char *)&s[len];
	return (res);
}
