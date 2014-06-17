/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 16:07:51 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 16:07:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pgt(t_env *gfx, char **param)
{
	t_player	*current;
	t_case		*cell;

	current = get_player(gfx, ft_atoi(param[1]));
	cell = gfx->g->map[current->x + current->y * gfx->g->msize[1]];
	if (ft_atoi(param[2]) == 0)
	{
		player->food++;
		cell->food--;
	}
	else
	{
		player->stones[ft_atoi(param[2]) - 1]++;
		cell->stones[ft_atoi(param[2]) - 1]--;
	}
}
