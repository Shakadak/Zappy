/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recah.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:40:33 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:40:34 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					recspe(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == '`')
		alpha->digimone = recnm(alpha->digimone, key, i, val);
	if (key->key[i - 1] == (int)123)
		alpha->digimtwo = recnm(alpha->digimtwo, key, i, val);
	if (key->key[i - 1] == (int)124)
		alpha->digimthree = recnm(alpha->digimthree, key, i, val);
	if (key->key[i - 1] == (int)125)
		alpha->digimfour = recnm(alpha->digimfour, key, i, val);
	if (key->key[i - 1] == (int)126)
		alpha->digimfive = recnm(alpha->digimfive, key, i, val);
	if (key->key[i - 1] == (int)127)
		alpha->digimsix = recnm(alpha->digimsix, key, i, val);
	return ;
}

static void					recrz(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'r')
		alpha->r = recnm(alpha->r, key, i, val);
	if (key->key[i - 1] == 's')
		alpha->s = recnm(alpha->s, key, i, val);
	if (key->key[i - 1] == 't')
		alpha->t = recnm(alpha->t, key, i, val);
	if (key->key[i - 1] == 'u')
		alpha->u = recnm(alpha->u, key, i, val);
	if (key->key[i - 1] == 'v')
		alpha->v = recnm(alpha->v, key, i, val);
	if (key->key[i - 1] == 'w')
		alpha->w = recnm(alpha->w, key, i, val);
	if (key->key[i - 1] == 'x')
		alpha->x = recnm(alpha->x, key, i, val);
	if (key->key[i - 1] == 'y')
		alpha->y = recnm(alpha->y, key, i, val);
	if (key->key[i - 1] == 'z')
		alpha->z = recnm(alpha->z, key, i, val);
	recspe(alpha, key, i, val);
}

static void					recgq(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'g')
		alpha->g = recnm(alpha->g, key, i, val);
	if (key->key[i - 1] == 'h')
		alpha->h = recnm(alpha->h, key, i, val);
	if (key->key[i - 1] == 'i')
		alpha->i = recnm(alpha->i, key, i, val);
	if (key->key[i - 1] == 'j')
		alpha->j = recnm(alpha->j, key, i, val);
	if (key->key[i - 1] == 'k')
		alpha->k = recnm(alpha->k, key, i, val);
	if (key->key[i - 1] == 'l')
		alpha->l = recnm(alpha->l, key, i, val);
	if (key->key[i - 1] == 'm')
		alpha->m = recnm(alpha->m, key, i, val);
	if (key->key[i - 1] == 'n')
		alpha->n = recnm(alpha->n, key, i, val);
	if (key->key[i - 1] == 'o')
		alpha->o = recnm(alpha->o, key, i, val);
	if (key->key[i - 1] == 'p')
		alpha->p = recnm(alpha->p, key, i, val);
	if (key->key[i - 1] == 'q')
		alpha->q = recnm(alpha->q, key, i, val);
	recrz(alpha, key, i, val);
}

static void					recah2(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (key->key[i - 1] == 'a')
		alpha->a = recnm(alpha->a, key, i, val);
	if (key->key[i - 1] == 'b')
		alpha->b = recnm(alpha->b, key, i, val);
	if (key->key[i - 1] == 'c')
		alpha->c = recnm(alpha->c, key, i, val);
	if (key->key[i - 1] == 'd')
		alpha->d = recnm(alpha->d, key, i, val);
	if (key->key[i - 1] == 'e')
		alpha->e = recnm(alpha->e, key, i, val);
	if (key->key[i - 1] == 'f')
		alpha->f = recnm(alpha->f, key, i, val);
	recgq(alpha, key, i, val);
}

void						recah(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val)
{
	if (is_capable(key->key[i]) == 1)
	{
		key->key[i] = (int)key->okey[i] + 64;
		alpha->hold_up = recnm(alpha->hold_up, key, i, val);
		return ;
	}
	if (is_scapable(key->key[i]) == 1)
	{
		key->key[i] = (int)key->okey[i] + 32;
		alpha->big_up = recnm(alpha->big_up, key, i, val);
		return ;
	}
	if (alpha == NULL)
		alpha = (t_alpha *)malloc(sizeof(t_alpha));
	if (key->key[i] == '\0')
	{
		if (val == NULL)
			alpha->val = NULL;
		else
			alpha->val = ft_strclone(val);
		return ;
	}
	i++;
	recah2(alpha, key, i, val);
}
