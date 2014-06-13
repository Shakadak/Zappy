/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:07:54 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/21 17:08:35 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char		**sstradd(char **tmp, char *toadd)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tmp[i] != '\0')
		i++;
	tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(toadd));
	while (toadd[j] != '\0')
	{
		tmp[i][j] = toadd[j];
		tmp[i][j + 1] = '\0';
		j++;
	}
	tmp[i + 1] = '\0';
	toadd = NULL;
	free(toadd);
	return (tmp);
}

static t_count	init_tcount(t_count c)
{
	c.i = 0;
	c.j = 0;
	c.k = 0;
	c.check = 0;
	c.res = 0;
	return (c);
}

static char		**ft_strsplit_(const char *tosplit, char c, char **res)
{
	char		*tmp;
	t_count		k;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(tosplit) + 2));
	k = init_tcount(k);
	while (tosplit[k.i] == (char)c && tosplit[k.i] != '\0')
		k.i++;
	while (tosplit[k.i] != '\0')
	{
		if (k.i == 0 && tosplit[k.i] == (char)c && tosplit[k.i + 1] != (char)c)
			k.i++;
		if (tosplit[k.i] == (char)c && tosplit[k.i + 1] != (char)c)
		{
			res = sstradd(res, tmp);
			return (ft_strsplit_(&tosplit[k.i + 1], c, res));
		}
		if (tosplit[k.i] != (char)c)
		{
			tmp[k.j] = tosplit[k.i];
			tmp[k.j + 1] = '\0';
			k.j++;
		}
		k.i++;
	}
	return (sstradd(res, tmp));
}

static int		ft_countchar(const char *str, char c)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			check++;
		i++;
	}
	return (check);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**res;

	res = (char **)malloc(sizeof(char *) * (ft_countchar(s, c) + 3));
	res[0] = '\0';
	res = ft_strsplit_(s, c, res);
	return (res);
}
