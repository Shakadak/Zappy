/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recnm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:41:27 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:41:29 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_alpha				*recnm(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (alpha == NULL)
	{
		alpha = (t_alpha *)malloc(sizeof(t_alpha));
		recah(alpha, key, i, val);
		return (alpha);
	}
	if (alpha != NULL)
	{
		recah(alpha, key, i, val);
		return (alpha);
	}
	return (alpha);
}
