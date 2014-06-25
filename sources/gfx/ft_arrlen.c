/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:07:06 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:50:49 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrlen(void **array)
{
	int	len;

	ft_putendl("ft_arrlen in");
	len = 0;
	while (*array++)
		len ++;
	ft_putendl("ft_arrlen in");
	return (len);
}
