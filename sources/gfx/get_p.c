/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 18:17:36 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 12:48:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_cmds.h"

void	get_pd(char *cmd)
{
	if (*cmd == 'i')
		return (pdi);
	if (*cmd == 'r')
		return (pdr);
	return (NULL);
}

void	get_pi(char *cmd)
{
	if (*cmd == 'c')
		return (pdi);
	if (*cmd == 'e')
		return (pie);
	if (*cmd == 'n')
		return (pin);
	return (NULL);
}
