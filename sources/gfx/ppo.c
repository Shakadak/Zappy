/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:42:19 by npineau           #+#    #+#             */
/*   Updated: 2014/06/22 16:58:15 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	ppo(t_env *gfx, char **param)
{
	t_player	*current;
	int			pos[2];

	current = get_player(gfx, ft_atoi(param[1]), NULL, PLAYER);
	pos[0] = current->x;
	pos[1] = current->y;
	current->x = ft_atoi(param[2]);
	current->y = ft_atoi(param[3]);
	current->dir = ft_atoi(param[4]);
	if (pos[0] != current->x || pos[1] != current->y)
		current->action = MOVE;
}
