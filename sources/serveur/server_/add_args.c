/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 18:55:33 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 18:55:36 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bircd.h"

int					getteams(t_env *e, char **argv, int j)
{
	int				i;

	i = 0;
	while (argv[i] != '\0' && strncmp(argv[i], "-", 1))
	{
		e->teams = (t_team *)realloc(e->teams, (sizeof(t_team)
			* (e->nbteam + 1)));
		e->teams[e->nbteam].nbpl = 0;
		e->teams[e->nbteam].name = ft_strclone(argv[i]);
		e->teams[e->nbteam].fork = (int *)malloc(sizeof(int) * 1);
		e->teams[e->nbteam].forknb = 0;
		e->nbteam++;
		i++;
	}
	return (i + j);
}

void				add_args(t_env *e, char **argv)
{
	int				i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i + 1] != '\0')
		{
			if (!ft_strcmp(argv[i], "-p"))
				e->port = atoi(argv[i + 1]);
			if (!ft_strcmp(argv[i], "-x"))
				e->map.xlen = atoi(argv[i + 1]);
			if (!ft_strcmp(argv[i], "-y"))
				e->map.ylen = atoi(argv[i + 1]);
			if (!ft_strcmp(argv[i], "-c"))
				e->maxpl = atoi(argv[i + 1]);
			if (!ft_strcmp(argv[i], "-t"))
				e->time_unit = atoi(argv[i + 1]);
			if (!ft_strcmp(argv[i], "-n"))
				i = getteams(e, &argv[i + 1], i);
		}
		i++;
	}
}
