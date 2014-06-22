/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:41:34 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:41:35 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*src(char *index, struct s_alpha *data)
{
	struct s_okey			*key;
	char					*res;

	key = malloc(sizeof(t_okey));
	key->key = malloc(sizeof(char) * (ft_strlen(index) + 1));
	key->okey = malloc(sizeof(char) * (ft_strlen(index) + 1));
	key->key[0] = '\0';
	ft_strcpy(key->key, index);
	ft_strcpy(key->okey, index);
	res = srchah(data, key, 0, "");
	ft_memdel((void **)&key->key);
	ft_memdel((void **)&key->okey);
	ft_memdel((void **)&key);
	return (res);
}
