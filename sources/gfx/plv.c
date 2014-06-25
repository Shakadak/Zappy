/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:53:19 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:38:31 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	plv(t_env *gfx, char **param)
{
	if (ft_arrlen((void **)param) != 3)
		return ;
	get_player(gfx, ft_atoi(param[1]), NULL, PLAYER)->level = ft_atoi(param[2]);
}
