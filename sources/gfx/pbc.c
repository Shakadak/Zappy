/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:32:15 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 17:03:00 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	pbc(t_env *gfx, char **param)
{
	get_player(gfx, ft_atoi(param[1]), 0, PLAYER)->action = BROADCAST;
}
