/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getuntil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:06:03 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 04:06:04 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"
#include "libft.h"
#include "bircd.h"

static int				getlenuntil(char c, char *str)
{
	int					i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char					*getuntil(char c, char *str)
{
	char				*res;
	int					i;

	i = 0;
	res = (char *)malloc(sizeof(char) * getlenuntil(c, str));
	while (str[i] != c && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
