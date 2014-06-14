/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 00:41:19 by gdefrait          #+#    #+#             */
/*   Updated: 2014/01/28 00:41:21 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						rec(char *str, char *index, struct s_alpha *data)
{
	struct s_okey			*key;

	key = malloc(sizeof(t_okey));
	key->key = malloc(sizeof(char) * (ft_strlen(index) + 1));
	key->okey = malloc(sizeof(char) * (ft_strlen(index) + 1));
	key->key[0] = '\0';
	key->okey[0] = '\0';
	ft_strcpy(key->key, index);
	ft_strcpy(key->okey, index);
	recah(data, key, 0, str);
	ft_memdel((void **)&key->key);
	ft_memdel((void **)&key->okey);
	ft_memdel((void **)&key);
	return ;
}
