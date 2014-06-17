/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_by_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 18:15:07 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 12:48:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_player	*get_player(t_env *gfx, int id, char *team, t_ptype type)
{
	int			i;
	int			j;
	t_player	*current;

	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < 256)
		{
			if (gfx->g->teams[i]->players[j]->type == type)
			{
				current = gfx->g->team[i]->players[j];
				if (type == VOID && ft_strequ(team, gfx->g->teams[i]->name))
					return (current);
				if (type != VOID && current->id == id)
					return (current);
			}
			i++;
		}
		j++;
	}
	return (NULL);
}
