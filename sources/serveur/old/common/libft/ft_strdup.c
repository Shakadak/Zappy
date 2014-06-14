/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:59:16 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 17:59:20 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || s == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(s));
	while ((char)s[i] != '\0')
	{
		dest[i] = (char)s[i];
		dest[i + 1] = '\0';
		i++;
	}
	return (dest);
}
