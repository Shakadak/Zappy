/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tna.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 15:29:25 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 16:37:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	tna(t_env *gfx, char **param)
{
	int		i;
	int		j;

	if (ft_arrlen((void **)param) != 2)
		return ;
	i = 0;
	while (i < 256)
	{
		if ((gfx->shm.shm->teams + i)->name == NULL)
		{
			(gfx->shm.shm->teams + i)->name = ft_strdup(param[1]);
			j = 0;
			while (j < 256)
				(gfx->shm.shm->teams + i)->players[j++].type = VOID;
			return ;
		}
		i++;
	}
}

void	new_team(t_env *gfx, char *name)
{
	char	*cmd;

	cmd = ft_strjoin("tna ", name);
	do_command(gfx, cmd);
	ft_strdel(&cmd);
}
