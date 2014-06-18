/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:29:25 by npineau           #+#    #+#             */
/*   Updated: 2014/06/18 18:14:21 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	tna(t_env *gfx, char **param)
{
	int		i;
	int		j;

	i = 0;
	while (i < 256)
	{
		if ((gfx->shm.shm->teams + i)->name == NULL)
		{
			(gfx->shm.shm->teams + i)->name = ft_strdup(param[1]);
			j = 0;
			while (j < 256)
				(gfx->shm.shm->teams + i)->players[j++].type = VOID;
			return ;
		}
		i++;
	}
}
