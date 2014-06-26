/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:35:19 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/26 15:25:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	enw(t_env *gfx, char **param)
{
	t_player	*egg;
	char		*team;

	if (ft_arrlen((void **)param) != 5)
		return ;
	team = get_team(gfx, ft_atoi(param[2]), PLAYER);
	egg = get_player(gfx, 0, team, VOID);
	egg->type = EGG;
	egg->id = ft_atoi(param[1]);
	egg->x = ft_atoi(param[3]);
	egg->y = ft_atoi(param[4]);
	egg->level = 0;
}
