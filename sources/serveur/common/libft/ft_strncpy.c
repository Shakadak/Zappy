/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:00:04 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:00:06 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	if (!s2 || s2 == NULL)
		return (NULL);
	ptr = s1;
	while ((char)*s2)
	{
		if (!n--)
			return (ptr);
		*s1++ = (char)*s2++;
	}
	while (n--)
		*s1++ = 0;
	return (ptr);
}
