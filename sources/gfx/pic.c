/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:51:50 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 14:38:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pic(t_env *gfx, char **param)
{
	int			i;

	if (ft_arrlen((void **)param) < 5)
		return ;
	i = 4;
	while (param[i])
	{
		get_player(gfx, ft_atoi(param[i]), NULL, PLAYER)->action = INCANT;
		i++;
	}
}
