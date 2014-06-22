/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 16:16:35 by npineau           #+#    #+#             */
/*   Updated: 2014/06/22 16:47:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"


void	draw_player(t_env *gfx, t_player p)
{
	if (p.action == GET) ;
	else if (p.action == DROP) ;
	else if (p.action == INCANT) ;
	else if (p.action == SUCCESS) ;
	else if (p.action == FAIL) ;
	else if (p.action == LAY) ;
	else if (p.action == DIE) ;
	else if (p.action == BROADCAST) ;
	else if (p.action == EXPULSE) ;
	else if (p.action == MOVE)
		draw_move(gfx, p);
	else if (p.action == TURN) ;
	else ;
}

void	draw_egg(t_env *gfx, t_player e)
{
	(void)gfx;
	(void)e;
}

void	draw_entity(t_env *gfx)
{
	int	t;
	int	p;

	t = 0;
	while (t < 256)
	{
		p = 0;
		while (p < 256)
		{
			if (gfx->shm.shm->teams[t].players[p].type == PLAYER)
				draw_player(gfx, gfx->shm.shm->teams[t].players[p]);
			else if (gfx->shm.shm->teams[t].players[p].type == PLAYER)
				draw_egg(gfx, gfx->shm.shm->teams[t].players[p]);
			p++;
		}
		t++;
	}
}
