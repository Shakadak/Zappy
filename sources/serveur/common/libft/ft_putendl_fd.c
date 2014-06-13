/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:10:35 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:10:36 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s && s != NULL)
	{
		write(fd, (char *)s, ft_strlen((char *)s));
		write(fd, "\n", 1);
	}
}
