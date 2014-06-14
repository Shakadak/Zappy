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

int					getteams(t_env *e, char **argv, int j)
{
	int				i;

	i = 0;
	while (argv[i] != '\0' && strncmp(argv[i], "-", 1))
	{
		e->teams[e->nbteam].nbpl = 0;
		e->teams[e->nbteam].name = ft_strclone(argv[i]);
		e->nbteam++;
		e->teams = (t_team *)realloc(e->teams, sizeof(t_team) * (e->nbteam + 1));
		i++;
	}
	return (i + j);
}

void				add_args(t_env *e, char **argv)
{
	int				i;

	i = 0;
	ft_putstr("YOYO");
	while (argv[i + 1] != '\0')
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
		i++;
	}
	//if (!ft_strcmp(argv[i], "-p"))
	//	e->port = ft_strclone(argv[i + 1]);
}
//e->maxpl
//e->t
int					*rand_ressources(void)
{
	int				*res;
	static int		seed = 40;
	int				i;

	i = 0;
	seed += 3;
	srand(seed);
	res = (int *)malloc(sizeof(int) * 7);
	while (i < NBRESSOURCE)
	{
		res[i] = rand() % 5;
		i++;
	}
	return (res);
}
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

void				init_env(t_env *e, char **argv)
{
	int				i;
	int				j;
	struct rlimit	rlp;
	time_t			tloc;

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
	e->wpl = 0;
	e->graphnb = 0;
	e->graphfd = (int *)malloc(sizeof(int) * 1);
	e->tnbpl = 0;
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
	add_args(e, argv);
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
	e->teams = (t_team *)malloc(sizeof(t_team) * 1);
	return ;
}

//o pire on execute les actions d abord tt court pr le moment et on lance timer apres
//coder encore la fonction pour avoir le 5eme atoi, etc... ah nn cte pr le graphik
//partie graphique.
//loop general.
//coder aussi send_res;
