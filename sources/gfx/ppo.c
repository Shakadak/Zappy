/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:42:19 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 13:01:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	ppo(t_env *gfx, char **param)
{
	t_player	current;

	current = get_player(gfx, ft_atoi(param[1]), NULL, PLAYER);
	current->x = ft_atoi(param[2]);
	current->y = ft_atoi(param[3]);
}
