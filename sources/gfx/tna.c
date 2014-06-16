/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:29:25 by npineau           #+#    #+#             */
/*   Updated: 2014/06/16 17:37:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	tna(t_env *gfx, char **param)
{
	int		i;
	int		j;

	i = 0;
	while (i < 256)
	{
		if (gfx->g->teams[i]->name == NULL)
		{
			gfx->g->teams[i]->name = ft_strdup(param[1]);
			j = 0;
			while (j < 256)
				gfx->g->teams[i]->players[j++] = -2;
			break ;
		}
		i++;
	}
}
