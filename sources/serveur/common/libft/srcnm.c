/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcnm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:44:48 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:44:49 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_alpha				*srcnm(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (alpha == NULL)
	{
		srchah(NULL, key, i, val);
		return (NULL);
	}
	if (alpha != NULL)
	{
		srchah(alpha, key, i, val);
		return (alpha);
	}
	return (alpha);
}
