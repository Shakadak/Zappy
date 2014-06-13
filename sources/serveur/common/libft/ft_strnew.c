/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:03:59 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/21 17:35:04 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * size);
	if (!size)
		return (NULL);
	while (i <= (int)size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
