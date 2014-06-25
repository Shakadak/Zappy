/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:28:03 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:38:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pin(t_env *gfx, char **param)
{
	int			i;
	t_player	*current;

	if (ft_arrlen((void **)param) != 11)
		return ;
	current = get_player(gfx, ft_atoi(param[1]), 0, PLAYER);
	current->x = ft_atoi(param[2]);
	current->y = ft_atoi(param[3]);
	current->food = ft_atoi(param[4]);
	i = 0;
	while (i < 6)
	{
		current->stones[i] = ft_atoi(param[i + 5]);
		i++;
	}
}
