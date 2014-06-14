/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:01:49 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:01:51 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if ((!s1 && !s2) || (s1 == NULL && s2 == NULL))
		return (0);
	while ((char)s1[i] == (char)s2[i]
		&& (char)s1[i] != '\0' && (char)s2[i] != '\0')
		i++;
	if ((char)s1[i] == '\0')
		return (-(char)s2[i]);
	if ((char)s2[i] == '\0')
		return ((char)s1[i]);
	return ((char)s1[i] - (char)s2[i]);
}
