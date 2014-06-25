/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:46:54 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/25 16:48:09 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	seg(t_env *gfx, char **param)
{
	if (ft_arrlen((void **)param) != 2)
		return ;
	gfx->shm.shm->winner = ft_strtrimc(param[1], '\n');
	ft_putstr("team ");
	ft_putstr(gfx->shm.shm->winner);
	ft_putendl(" win !");
}
