/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:29:34 by npineau           #+#    #+#             */
/*   Updated: 2014/06/08 18:53:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int	add_dir(int param, int dir)
{
	return (param | dir);
}

int	rem_dir(int param, int dir)
{
	return (param & ~dir);
}

int	key_update(SDL_Event *ev, int current, int dir)
{
	if (ev->type == SDL_KEYDOWN)
		return (add_dir(current, dir));
	if (ev->type == SDL_KEYUP)
		return (rem_dir(current, dir));
	return (current);
}
