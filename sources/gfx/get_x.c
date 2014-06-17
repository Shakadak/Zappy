/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 17:36:36 by npineau           #+#    #+#             */
/*   Updated: 2014/06/17 17:19:53 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_cmds.h"

void	*get_e(char *cmd)
{
	if (*cmd == 'b')
		return (ebo);
	if (*cmd == 'd')
		return (edi);
	if (*cmd == 'h')
		return (eht);
	if (*cmd == 'n')
		return (enw);
	return (NULL);
}

void	*get_p(char *cmd)
{
	if (*cmd == 'b')
		return (pbc);
	if (*cmd == 'd')
		return (get_pd(cmd + 1));
	if (*cmd == 'e')
		return (pex);
	if (*cmd == 'f')
		return (pfk);
	if (*cmd == 'g')
		return (pgt);
	if (*cmd == 'i')
		return (get_pi(cmd + 1));
	if (*cmd == 'l')
		return (plv);
	if (*cmd == 'n')
		return (pnw);
	if (*cmd == 'p')
		return (ppo);
	return (NULL);
}

void	*get_s(char *cmd)
{
	if (*cmd == 'b')
		return (sbp);
	if (*cmd == 'e')
		return (seg);
	if (*cmd == 'g')
		return (sgt);
	if (*cmd == 'm')
		return (smg);
	if (*cmd == 'u')
		return (suc);
	return (NULL);
}

void	*get_x(char *cmd)
{
	if (*cmd == 'b')
		return (bct);
	if (*cmd == 'e')
		return (get_e(cmd + 1));
	if (*cmd == 'm')
		return (msz);
	if (*cmd == 'p')
		return (get_p(cmd + 1));
	if (*cmd == 's')
		return (get_s(cmd + 1));
	if (*cmd == 't')
		return (tna);
	return (NULL);
}
