/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:24:03 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/22 20:24:05 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int n, int a)
{
	if (n == 0)
		return (1);
	return (a * ft_power(n - 1, a));
}

static int		ft_clean(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

static size_t	ft_strlendigit(const char *str, int i)
{
	int res;

	res = 0;
	while (ft_isdigit(str[res + i]))
	{
		res++;
	}
	return (res + i);
}

int				ft_atoi(const char *nptr)
{
	int		i;
	t_count	c;

	c.check = 0;
	c.res = 0;
	i = ft_clean(nptr);
	if (!nptr)
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			c.check = 1;
		i = i + 1;
	}
	c.len = ft_strlendigit(nptr, i) - 1;
	while (ft_isdigit(nptr[i]))
	{
		if (c.check)
			c.res = c.res - (nptr[i] - '0') * ft_power(c.len - i, 10);
		else
			c.res = c.res + (nptr[i] - '0') * ft_power(c.len - i, 10);
		i++;
	}
	return (c.res);
}
