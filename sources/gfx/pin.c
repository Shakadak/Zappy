/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 12:28:03 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 12:33:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pin(t_env *gfx, char **param)
{
	int			i;
	t_player	*current;

	current = get_player(gfx, ft_atoi(param[1]));
	current->x = ft_atoi(param[2]);
	current->y = ft_atoi(param[3]);
	current->food = ft_atoi(param[4]);
	i = 0;
	while (i < 6)
	{
		cell->stones[i] = ft_atoi(param[i + 5]);
		i++;
	}

}
