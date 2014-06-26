/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:41:00 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:37:51 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"gfx.h"

void	pdi(t_env *gfx, char **param)
{
	t_player	*current;

	if (ft_arrlen((void **)param) != 2)
		return ;
	current = get_player(gfx, ft_atoi(param[1]), NULL, PLAYER);
	current->type = VOID;
	current->id = -1;
	current->action = DIE;
}