/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:55:04 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 12:20:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ebo(t_env *gfx, char **param)
{
	t_player	*egg;

	egg = get_player(gfx, ft_atoi(param[1]), NULL, EGG);
	egg->type = VOID;
	egg->id = -1;
}
