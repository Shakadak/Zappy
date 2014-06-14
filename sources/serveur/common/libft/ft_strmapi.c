/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:05:13 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:05:15 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !f || s == NULL || f == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s && f)
	{
		while ((char)s[i] != '\0')
		{
			dest[i] = f(i, (char)s[i]);
			i++;
		}
	}
	return (dest);
}
