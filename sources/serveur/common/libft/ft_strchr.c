/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:00:44 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:00:46 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s || s == NULL)
		return (NULL);
	while ((char)s[i] != '\0' && (char)s[i] != c)
		i++;
	if ((char)s[i] != c)
		return (0);
	return ((char *)&s[i]);
}
