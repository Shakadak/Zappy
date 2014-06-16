/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:39:12 by npineau           #+#    #+#             */
/*   Updated: 2014/06/16 17:58:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	create_player(t_player *current, char **param)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		if (current[i]->id < 0)
		{
			current[i]->id = ft_atoi(param[1]);
			current[i]->x = ft_atoi(param[2]);
			current[i]->y = ft_atoi(param[3]);
			current[i]->level = ft_atoi(param[5]);
			current[i]->food = 10;
			break ;
		}
		i++;
	}
}

void		pnw(t_env *gfx, char **param)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		if (ft_strequ(gfx->g->teams[i]->name, param[6]))
		{
			create_player(gfx->g->team[i]->players, param);
			return ;
		}
		i++;
	}
}
