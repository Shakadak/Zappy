/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:42:19 by npineau           #+#    #+#             */
/*   Updated: 2014/06/16 18:00:04 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ppo(t_env *gfx, char **param)
{
	int	i;
	int	j;
	int	player;

	player = ft_atoi(param[1]);
	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < 256)
		{
			if (gfx->g->teams[i]->players[j]->id == player)
			{
				gfx->g->teams[i]->players[j]->x = ft_atoi(param[2]);
				gfx->g->teams[i]->players[j]->x = ft_atoi(param[3]);
				return ;
			}
		}
	}
}
