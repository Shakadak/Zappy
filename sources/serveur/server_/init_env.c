/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:16:45 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:16:47 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include "bircd.h"

t_case				new_case(void)
{
	t_case			res;
	static int		seed = 40;
	int				i;

	res.plonit = 0;
	res.egg = 0;
	i = 0;
	seed += 3;
	srand(seed);
	while (i < NBRESSOURCE)
	{
		res.r[i] = rand() % 5;
		i++;
	}
	return (res);
}

void				init_debug(t_env *e)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	e->debug = (char **)malloc(sizeof(char *) * e->map.ylen + 1);
	while (i < e->map.ylen)
	{
		j = 0;
		e->debug[i] = (char *)malloc(sizeof(char) * e->map.xlen + 1);
		while (j < e->map.xlen)
		{
			e->debug[i][j] = '-';
			j++;
		}
		i++;
	}
	return ;
}

void				init_env__(t_env *e, char **argv)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	add_args(e, argv);
	init_debug(e);
	e->map.map = (t_case **)malloc(sizeof(t_case *) * e->map.ylen);
	i = -1;
	while (++i < e->map.ylen)
	{
		e->map.map[i] = (t_case *)malloc(sizeof(t_case) * e->map.xlen);
		j = -1;
		while (++j < e->map.xlen)
		{
			e->map.map[i][j] = new_case();
		}
	}
	e->map.updated = 0;
	return ;
}

void				init_env_(time_t tloc, t_env *e, char **argv)
{
	e->maxpl = STANDARD_MAXPL;
	e->time_unit = STANDARD_T;
	e->port = STANDARD_PORT;
	e->map.xlen = STANDARD_XLEN;
	e->map.ylen = STANDARD_YLEN;
	e->generation_timer = time(&tloc);
	e->waitingpl = NULL;
	e->teams = (t_team *)malloc(sizeof(t_team) * 1);
	e->nbteam = 0;
	e->fork = (int *)malloc(sizeof(int) * 1);
	e->forknb = 0;
	e->eggs = (t_egg *)malloc(sizeof(t_egg) * 1);
	e->nbegg = 0;
	e->pl = (t_pl *)malloc(sizeof(t_pl) * 1);
	e->nbpl = 0;
	return (init_env__(e, argv));
}

void				init_env(t_env *e, char **argv)
{
	int				i;
	struct rlimit	rlp;
	time_t			tloc;

	tloc = 0;
	X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)Xv(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
	e->nicknames = (t_alpha *)malloc(sizeof(t_alpha));
	i = 0;
	while (i < e->maxfd)
	{
		clean_fd(&e->fds[i]);
		i++;
	}
	i = 0;
	e->wpl = 0;
	e->map.updated = 0;
	e->graphnb = 0;
	e->graphfd = (int *)malloc(sizeof(int) * 1);
	e->tnbpl = 0;
	e->general_timer = 0;
	return (init_env_(tloc, e, argv));
}
