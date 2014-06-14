/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:56:49 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 17:56:58 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void				ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	i = n;
	if (s != NULL && n != 0)
		str = (unsigned char *)s;
	while (n > 0 && s != NULL)
	{
		str[i - n] = 0;
		n--;
	}
}
