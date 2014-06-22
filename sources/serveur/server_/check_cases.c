/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:10:02 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:10:04 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

char					*check_cases_down(t_env *e, int y, int x, int hm)
{
	int					xc;
	int					count;
	char				*res;

	xc = hm;
	count = 1;
	y = getrc(y, 'Y', e);
	res = lookoncase(e, y, getrc(x + hm, 'X', e), (hm * hm));
	res = ft_stradd(res, ", ");
	while (--xc > 0)
	{
		res = ft_stradd(ft_straddrp(res, lookoncase(e, y, getrc(x + xc, 'X', e),
			(hm * hm) + count)), ", ");
		count++;
	}
	xc = -1;
	while (++xc <= hm)
	{
		res = ft_straddrp(res, lookoncase(e, y, getrc(x - xc, 'X', e), (hm * hm)
			+ count));
		if (xc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_up(t_env *e, int y, int x, int hm)
{
	int					xc;
	int					count;
	char				*res;

	xc = hm;
	count = 1;
	y = getrc(y, 'Y', e);
	res = lookoncase(e, y, getrc(x - hm, 'X', e), (hm * hm));
	res = ft_stradd(res, ", ");
	while (--xc > 0)
	{
		res = ft_stradd(ft_straddrp(res, lookoncase(e, y, getrc(x - xc, 'X', e),
			(hm * hm) + count)), ", ");
		count++;
	}
	xc = -1;
	while (++xc <= hm)
	{
		res = ft_straddrp(res, lookoncase(e, y, getrc(x + xc, 'X', e), (hm * hm)
			+ count));
		if (xc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_left(t_env *e, int y, int x, int hm)
{
	int					yc;
	int					count;
	char				*res;

	yc = hm;
	count = 1;
	x = getrc(x, 'X', e);
	res = lookoncase(e, getrc(y - hm, 'Y', e), x, (hm * hm));
	res = ft_stradd(res, ", ");
	while (--yc > 0)
	{
		res = ft_stradd(ft_straddrp(res, lookoncase(e, getrc(y - yc, 'Y', e), x,
			(hm * hm) + count)), ", ");
		count++;
	}
	yc = -1;
	while (++yc <= hm)
	{
		res = ft_straddrp(res, lookoncase(e, getrc(y + yc, 'Y', e), x, (hm * hm)
			+ count));
		if (yc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}

char					*check_cases_right(t_env *e, int y, int x, int hm)
{
	int					yc;
	int					count;
	char				*res;

	yc = hm;
	count = 1;
	x = getrc(x, 'X', e);
	res = lookoncase(e, getrc(y + hm, 'Y', e), x, (hm * hm));
	res = ft_stradd(res, ", ");
	while (--yc > 0)
	{
		res = ft_stradd(ft_straddrp(res, lookoncase(e, getrc(y + yc, 'Y', e), x,
			(hm * hm) + count)), ", ");
		count++;
	}
	yc = -1;
	while (++yc <= hm)
	{
		res = ft_straddrp(res, lookoncase(e, getrc(y - yc, 'Y', e), x, (hm * hm)
			+ count));
		if (yc != hm)
			res = ft_stradd(res, ", ");
		count++;
	}
	return (res);
}
