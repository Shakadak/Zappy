/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 15:50:12 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:37:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	msz(t_env *gfx, char **param)
{
	if (ft_arrlen((void **)param) != 3)
		return ;
	gfx->msize[0] = ft_atoi(param[1]);
	gfx->msize[1] = ft_atoi(param[2]);
}
