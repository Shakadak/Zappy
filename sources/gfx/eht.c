/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eht.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <jibanez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:17:42 by jibanez           #+#    #+#             */
/*   Updated: 2014/06/17 17:00:15 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	eht(t_env *gfx, char **param)
{
	get_player(gfx, ft_atoi(param[1]), 0, EGG)->level = 1;
}
