/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_const.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:32:50 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:32:52 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strlen_const(char const *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while ((char)str[i] != '\0')
		i++;
	return (i);
}
