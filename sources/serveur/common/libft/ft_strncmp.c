/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:17:25 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:17:26 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 || s1 == NULL) && (!s2 || s2 == NULL))
		return (0);
	if (!s2 || s2 == NULL)
		return ((unsigned char)s1[0]);
	if (!s1 || s1 == NULL)
		return ((unsigned char)s2[0]);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < (n - 1) && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
