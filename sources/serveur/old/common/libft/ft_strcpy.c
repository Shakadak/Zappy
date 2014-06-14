/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:59:27 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 17:59:30 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_strcpy(char *dest, const char *src)
{
	int						i;

	i = 0;
	if (!src)
		return (NULL);
	while ((char)src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char						*ft_strclone(char *toclone)
{
	char					*res;
	int						i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(toclone));
	res[0] = '\0';
	while (toclone[i] != '\0')
	{
		res[i] = toclone[i];
		res[i + 1] = '\0';
		i++;
	}
	return (res);
}
