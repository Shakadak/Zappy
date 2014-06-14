/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:05:47 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:05:49 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (!s1 || !s2 || s1 == NULL || s2 == NULL)
		return (0);
	while ((char)s1[i] == (char)s2[i] && (char)s1[i] != '\0'
		&& (char)s2[i] != '\0' && n > 0)
	{
		i++;
		n--;
	}
	if (((char)s1[i] == '\0' && (char)s2[i] == '\0') || n == 0)
		return (1);
	return (0);
}
