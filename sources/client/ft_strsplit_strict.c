/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_strict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:52:02 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:48:55 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char		*create_string(const char *s, char c, size_t num)
{
	size_t	len;
	size_t	i;
	size_t	cursor;
	char	*new_str;

	i = 0;
	cursor = 0;
	while (s[cursor] && i < num)
	{
		if (s[cursor] == c)
			i++;
		cursor++;
	}
	len = ft_strlenc(&s[cursor], c);
	new_str = ft_strnew(len + 1);
	ft_strncpy(new_str, &s[cursor], len);
	return (new_str);
}

char			**ft_strsplit_strict(const char *s, char c)
{
	char		**split;
	size_t		size;
	size_t		i;

	if (!s)
		return (NULL);
	size = ft_strcountc(s, c) + 2;
	if (!(split = (char **)ft_memalloc(size * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (i == (size - 1))
			split[i] = NULL;
		else
			split[i] = create_string(s, c, i);
		i++;
	}
	return (split);
}
