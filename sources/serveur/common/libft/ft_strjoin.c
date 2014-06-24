/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:17:06 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 19:17:08 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*join;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char)
		* (ft_strlen((char *)s1) + ft_strlen((char *)s2)));
	while ((char)s1[i] != '\0')
	{
		join[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[n] != '\0')
	{
		join[i] = (char)s2[n];
		i++;
		n++;
	}
	join[i] = '\0';
	return (join);
}

static char	*ft_stradd_(char *s1, char *join, const char *s2, int i)
{
	int		n;

	n = 0;
	while ((char)s2[n] != '\0')
	{
		join[i] = (char)s2[n];
		join[i + 1] = '\0';
		i++;
		n++;
	}
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (join);
}

char		*ft_stradd(char *s1, const char *s2)
{
	int		i;
	char	*join;

	i = 0;
	if (s2 == NULL)
		return (NULL);
	join = (char *)malloc(sizeof(char)
		* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (s1 != NULL)
	{
		while ((char)s1[i] != '\0')
		{
			join[i] = (char)s1[i];
			join[i + 1] = '\0';
			i++;
		}
	}
	return (ft_stradd_(s1, join, s2, i));
}

static char	*ft_straddrp_(char *s1, char *join, char *s2, int i)
{
	int		n;

	n = 0;
	while ((char)s2[n] != '\0')
	{
		join[i] = (char)s2[n];
		join[i + 1] = '\0';
		i++;
		n++;
	}
	if (s1 != NULL)
		ft_memdel((void **)&s1);
	if (s2 != NULL)
		ft_memdel((void **)&s2);
	return (join);
}

char		*ft_straddrp(char *s1, char *s2)
{
	int		i;
	char	*join;

	i = 0;
	if (s2 == NULL)
		return (NULL);
	join = (char *)malloc(sizeof(char)
		* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (s1 != NULL)
	{
		while ((char)s1[i] != '\0')
		{
			join[i] = (char)s1[i];
			join[i + 1] = '\0';
			i++;
		}
	}
	return (ft_straddrp_(s1, join, s2, i));
}
