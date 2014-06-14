/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:07:26 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/20 18:07:30 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *s1)
{
	int		i;
	char	*rev;
	int		s;

	i = 0;
	s = 0;
	if (!s1)
		return (NULL);
	rev = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while ((ft_strlen(s1) - i) > 0)
	{
		rev[i] = (char)s1[ft_strlen(s1) - i - 1];
		rev[i + 1] = '\0';
		i++;
	}
	while (rev[s] != '\0')
		s++;
	free(s1);
	s1 = NULL;
	return ((char *)rev);
}

static char	*ft_add_sign(int s, char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ((ft_strlen(str)) + 13));
	if (s == 1)
		dest[0] = '-';
	while ((char)str[i] != '\0' && s == 1)
	{
		dest[i + 1] = str[i];
		dest[i + 2] = '\0';
		i++;
	}
	dest[i + 1] = '\0';
	if (s == 0)
	{
		ft_memdel((void **)&dest);
		return ((char *)str);
	}
	ft_memdel((void **)&str);
	return ((char *)dest);
}

static char	*ft_itoa2(int n, char *str, int sc, int s)
{
	int		i;
	char	*dest;

	i = 0;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		str[i + 1] = '\0';
		n = (n / 10) - (n % 10 / 10);
		i++;
	}
	str[i] = '\0';
	if (!str)
		return (NULL);
	if (sc == 1)
	{
		dest = (char *)malloc(sizeof(char) * ((ft_strlen(str)) + 13));
		ft_strcpy(dest, "-2147483648");
		ft_memdel((void **)&str);
		return (dest);
	}
	return ((char *)ft_add_sign(s, ft_strrev((char *)str)));
}

char		*ft_itoa(int n)
{
	int		s;
	char	*str;
	int		sc;

	s = 0;
	sc = 0;
	str = (char *)malloc(sizeof(char) * 13);
	if (n < 0 || n == -2147483648)
	{
		n = -n;
		s = 1;
		if (n == -2147483648)
			sc = 1;
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (ft_itoa2(n, str, sc, s));
}
