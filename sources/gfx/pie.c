/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pie.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 17:03:22 by npineau           #+#    #+#             */
/*   Updated: 2014/06/18 18:13:30 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pie(t_env *gfx, char **param)
{
	int	pos;

	pos = ft_atoi(param[1]) + ft_atoi(param[2]) * gfx->msize[0];
	if (ft_atoi(param[3]))
		(gfx->shm.shm->map + pos)->action = SUCCESS;
	else
		(gfx->shm.shm->map + pos)->action = FAIL;
}
