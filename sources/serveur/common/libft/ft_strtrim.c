/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:07:13 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:07:15 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_blank(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\t')
		return (1);
	else
		return (0);
}

static int		ft_countnoblank(char const *s)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	while (is_blank(s[i]))
		i++;
	while (s[i])
	{
		i++;
		res++;
	}
	while (is_blank(s[i - 1]) && res)
	{
		i--;
		res--;
	}
	return (res);
}

char			*ft_strtrim(char const *s)
{
	char		*res;
	int			len;
	int			i;

	if (!s || s == NULL)
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen((char *)s));
	len = ft_countnoblank(s);
	i = 0;
	while (is_blank(*s))
		s++;
	while (len-- > 0)
	{
		res[i] = *s;
		s++;
		i++;
	}
	res[i] = 0;
	return (res);
}
