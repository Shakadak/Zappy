/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:25:38 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/25 14:38:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pfk(t_env *gfx, char **param)
{
	if (ft_arrlen((void **)param) != 2)
		return ;
	get_player(gfx, ft_atoi(param[1]), NULL, PLAYER)->action = LAY;
}
