/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_by_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:15:07 by npineau           #+#    #+#             */
/*   Updated: 2014/06/18 18:12:22 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

char	*get_team(t_env *gfx, int id, t_ptype type)
{
	int			i;
	int			j;

	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < 256)
		{
			if (gfx->shm.shm->teams[i].players[j].type == type)
			{
				if (gfx->shm.shm->teams[i].players[j].id == id)
					return (gfx->shm.shm->teams[i].name);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
