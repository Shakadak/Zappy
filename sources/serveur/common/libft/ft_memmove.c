/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:15:44 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:15:45 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = malloc(sizeof(void) * n);
	if (!src || !n || src == NULL)
		return (NULL);
	if (src != NULL)
	{
		ft_memcpy(temp, (char *)src, n);
		ft_memcpy(dest, temp, n);
		ft_memdel(&temp);
	}
	return (dest);
}
