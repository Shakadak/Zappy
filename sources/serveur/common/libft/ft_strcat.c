/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:00:17 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:00:20 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		l;
	char	*temp;

	i = 0;
	l = 0;
	temp = dest;
	if (!src || src == NULL)
		return (NULL);
	while (temp[l] != '\0')
	{
		dest[l] = temp[l];
		l++;
	}
	while ((char)src[i] != '\0')
	{
		dest[l] = (char)src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return (dest);
}
