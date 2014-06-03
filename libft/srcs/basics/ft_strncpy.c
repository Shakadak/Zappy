/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:40:08 by garm              #+#    #+#             */
/*   Updated: 2014/05/11 06:30:47 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (s1);
	ft_bzero(s1, n);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
