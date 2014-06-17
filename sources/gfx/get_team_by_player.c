/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_by_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:15:07 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 17:19:22 by npineau          ###   ########.fr       */
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
			if (gfx->g->teams[i].players[j].type == type)
			{
				if (gfx->g->teams[i].players[j].id == id)
					return (gfx->g->teams[i].name);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
