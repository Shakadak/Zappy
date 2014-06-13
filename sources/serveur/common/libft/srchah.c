/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srchah.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:42:00 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:42:03 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char					*srchsp(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == '`')
		return (srchah(alpha->digimone, key, i, val));
	if (key->key[i - 1] == (int)123)
		return (srchah(alpha->digimtwo, key, i, val));
	if (key->key[i - 1] == (int)124)
		return (srchah(alpha->digimthree, key, i, val));
	if (key->key[i - 1] == (int)125)
		return (srchah(alpha->digimfour, key, i, val));
	if (key->key[i - 1] == (int)126)
		return (srchah(alpha->digimfive, key, i, val));
	if (key->key[i - 1] == (int)127)
		return (srchah(alpha->digimsix, key, i, val));
	return (NULL);
}

static char					*srchrz(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'r')
		return (srchah(alpha->r, key, i, val));
	if (key->key[i - 1] == 's')
		return (srchah(alpha->s, key, i, val));
	if (key->key[i - 1] == 't')
		return (srchah(alpha->t, key, i, val));
	if (key->key[i - 1] == 'u')
		return (srchah(alpha->u, key, i, val));
	if (key->key[i - 1] == 'v')
		return (srchah(alpha->v, key, i, val));
	if (key->key[i - 1] == 'w')
		return (srchah(alpha->w, key, i, val));
	if (key->key[i - 1] == 'x')
		return (srchah(alpha->x, key, i, val));
	if (key->key[i - 1] == 'y')
		return (srchah(alpha->y, key, i, val));
	if (key->key[i - 1] == 'z')
		return (srchah(alpha->z, key, i, val));
	return (srchsp(alpha, key, i, val));
}

static char					*srchgq(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'g')
		return (srchah(alpha->g, key, i, val));
	if (key->key[i - 1] == 'h')
		return (srchah(alpha->h, key, i, val));
	if (key->key[i - 1] == 'i')
		return (srchah(alpha->i, key, i, val));
	if (key->key[i - 1] == 'j')
		return (srchah(alpha->j, key, i, val));
	if (key->key[i - 1] == 'k')
		return (srchah(alpha->k, key, i, val));
	if (key->key[i - 1] == 'l')
		return (srchah(alpha->l, key, i, val));
	if (key->key[i - 1] == 'm')
		return (srchah(alpha->m, key, i, val));
	if (key->key[i - 1] == 'n')
		return (srchah(alpha->n, key, i, val));
	if (key->key[i - 1] == 'o')
		return (srchah(alpha->o, key, i, val));
	if (key->key[i - 1] == 'p')
		return (srchah(alpha->p, key, i, val));
	if (key->key[i - 1] == 'q')
		return (srchah(alpha->q, key, i, val));
	return (srchrz(alpha, key, i, val));
}

static char					*srchah2(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'a')
		return (srchah(alpha->a, key, i, val));
	if (key->key[i - 1] == 'b')
		return (srchah(alpha->b, key, i, val));
	if (key->key[i - 1] == 'c')
		return (srchah(alpha->c, key, i, val));
	if (key->key[i - 1] == 'd')
		return (srchah(alpha->d, key, i, val));
	if (key->key[i - 1] == 'e')
		return (srchah(alpha->e, key, i, val));
	if (key->key[i - 1] == 'f')
		return (srchah(alpha->f, key, i, val));
	return (srchgq(alpha, key, i, val));
}

char						*srchah(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	struct s_alpha	*alpha2;

	if (alpha == NULL)
	{
		return (NULL);
		alpha2 = (t_alpha *)malloc(sizeof(t_alpha));
		alpha = alpha2;
	}
	if (is_capable(key->key[i]) == 1)
	{
		key->key[i] = (int)key->okey[i] + 64;
		return (srchah(alpha->hold_up, key, i, val));
	}
	if (is_scapable(key->key[i]) == 1)
	{
		key->key[i] = (int)key->okey[i] + 32;
		return (srchah(alpha->big_up, key, i, val));
	}
	if (key->key[i] == '\0')
	{
		if (alpha->val != NULL)
			return (getval(alpha->val));
	}
	i++;
	return (srchah2(alpha, key, i, val));
}
