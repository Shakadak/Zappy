/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:39:12 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 16:31:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void		pnw(t_env *gfx, char **param)
{
	int			i;
	t_player	*current;

	if (ft_arrlen((void **)param) != 7)
		return ;
	if ((current = get_player(gfx, 0, param[6], VOID)) == NULL)
		new_team(gfx, param[6]);
	current = get_player(gfx, 0, param[6], VOID);
	current->id = get_id(param[1]);
	current->x = ft_atoi(param[2]);
	current->y = ft_atoi(param[3]);
	current->level = ft_atoi(param[5]);
	current->dir = ft_atoi(param[4]);
	current->time = 0;
	current->action = NONE;
	current->food = 10;
	current->type = PLAYER;
	i = 0;
	while (i < 6)
	{
		current->stones[i] = 0;
		i++;
	}
}
