/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:58:58 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 17:59:02 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while ((char)s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_sstrlen(char **sstr)
{
	int		i;
	size_t	len;

	if (sstr == NULL)
		return (0);
	i = 0;
	len = 0;
	while (sstr[len])
	{
		i = 0;
		while (sstr[len][i])
			i++;
		len++;
	}
	return (len);
}
