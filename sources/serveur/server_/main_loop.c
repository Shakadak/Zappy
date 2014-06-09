/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:17:10 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:17:11 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

/*

//fonctions:
"pex #n\n" - Un joueur expulse.
"pbc #n M\n" Un joueur fait un broadcast.
"pic X Y L #n #n …\n" - Premier joueur lance l’incantation pour tous les 
suivants sur la case. 
"pfk #n\n" - Le joueur pond un œuf. 
"enw #e #n X Y\n" - L’œuf a été pondu sur la case par le joueur. 
"pdr #n i\n" - Le joueur jette une ressource. 
"pgt #n i\n" - Le joueur prend une ressource. 

//automation:
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 
//"bct X Y q q q q q q q\n" * nbr_cases "mct\n" Contenu de la carte (toutes les cases). 
"ppo #n X Y O\n" "ppo #n\n" Position d’un joueur. 
"plv #n L\n" "plv #n\n" Niveau d’un joueur. 
"pin #n X Y q q q q q q q\n" "pin #n\n" Inventaire d’un joueur. 
"pdi #n\n" - Le joueur est mort de faim. 
"eht #e\n" - L’œuf éclot.
"ebo #e\n" - Un joueur s’est connecté pour l’œuf. 
"edi #e\n" - L’œuf éclos est mort de faim. 
"seg N\n" - Fin du jeu. L’équipe donnée remporte la partie. 
"smg M\n" - Message du serveur. 
"sbp\n" - Mauvais paramètres pour la commande. 

//echange
"sgt T\n" "sgt\n" Demande de l’unité de temps courante sur le 
serveur. 
"sgt T\n" "sst T\n" Modification de l’unité de temps sur le serveur. 

//initialisation:
"msz X Y\n" "msz\n" Taille de la carte. 
"tna N\n" * nbr_equipes "tna\n" Nom des équipes. 
"bct X Y q q q q q q q\n" "bct X Y\n" Contenu d’une case de la carte. 


//connect "pnw #n X Y O L N\n" - Connexion d’un nouveau joueur. 
*/

void		g_send_pl(t_pl pl, int i, t_env *e)
{
	char	*tmp;

	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("ppo #");
		tmp = ft_stradd(tmp, ft_itoa(i));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.y));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(pl.dir));
		tmp = ft_stradd(tmp, "\n");
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void		g_send_case(t_case c, int x, int y, t_env *e)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (e->graphnb)
	{
		tmp = ft_strclone("bct ");
		tmp = ft_stradd(tmp, ft_itoa(x));
		tmp = ft_stradd(tmp, " ");
		tmp = ft_stradd(tmp, ft_itoa(y));
		i = -1;
		while (++i < NBRESSOURCE)
		{
			tmp = ft_stradd(tmp, " ");
			tmp = ft_stradd(tmp, ft_itoa(c.r[i]));
		}
		send_res(-1, tmp, e);
		free(tmp);
		tmp = NULL;
	}
	return ;
}

void	g_send_map(t_env *e)
{
	int	j;
	int	i;

	i = -1;
	j = -1;
	while (++i < e->map.ylen)
	{
		while (++j < e->map.xlen)
			g_send_case(e->map.map[i][j], j, i, e);
		j = -1;
	}
	return ;
}

void	load_function(int action, int pl, t_env *e)
{
	if (action == MOVE)
		move(e, pl);
	if (action == TAKE)
		take(e, pl);
	if (action == DROP)
		drop(e, pl);
	if (action == EJECT)
		eject(e, pl);
	if (action == FORK)
		fork_player(e, pl);
	if (action == INCANTATION)
		incantation(e, pl);
	if (action == CNB)
		connect_nbr(e, pl);
	if (action == BROADCAST)
		broadcast(e, pl);
	if (action == LVLUP)
		lvl_up(e, pl);
	if (action == INV)
		aff_inv(e, pl);
	if (action == SEE)
		see(e, pl);
}

void	g_send_egg(t_egg egg, int pl, int eggnb, t_env *e)
{
	char	*res;

	if (!egg.used)
	{
		res = ft_strclone("enw #");
		res = ft_stradd(res, ft_itoa(eggnb));
		res = ft_stradd(res, " #");
		res = ft_stradd(res, ft_itoa(pl));
		res = ft_stradd(res, " ");
		res = ft_stradd(res, ft_itoa(egg.x));
		res = ft_stradd(res, " ");
		res = ft_stradd(res, ft_itoa(egg.y));
		send_res(-1, res, e);
		res = NULL;
		free(res);
	}
	return ;
}

void		init_graph(t_env *e, int cs)
{
	int		i;

	i = 0;
	(void)cs;
	e->graphfd = (int *)realloc(e->graphfd, (sizeof(int) * (e->graphnb + 1)));
	e->graphnb++;
	while (i < e->nbpl)
	{
		if (e->pl[i].cs != -1)
			g_send_pl(e->pl[i], i, e);
		e->pl[i].updated = 0;
		i++;
	}
	g_send_map(e);
	i = e->nbegg;
	while (i > 0)
	{
		if (!e->eggs[i].used)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		i--;
	}
	i = e->wpl;
	while (i > 0)
	{
		if (e->forknb > 0)
		{
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		i--;
	}
	return ;
}

int			getacttime(int action)
{
	int		res;

	if (action == MOVE)
		res = 7;
	if (action == TAKE)
		res = 7;
	if (action == DROP)
		res = 7;
	if (action == EJECT)
		res = 7;
	if (action == FORK)
		res = 42;
	if (action == INCANTATION)
		res = 300;
	if (action == CNB)
		res = 0;
	if (action == BROADCAST)
		res = 7;
	if (action == LVLUP)
		res = 300;
	if (action == INV)
		res = 1;
	if (action == SEE)
		res = 7; //.nour
	return (res);
}

t_pl		new_tpl(t_env *e, int cs)
{
	t_pl	res;
	int		i;

	(void)e;
	i = 1;
	res.x = rand() % e->map.xlen;
	res.y = rand() % e->map.ylen;
	e->map.map[res.y][res.x].plonit++;
	res.action = 0;
	res.actionwait = 0;
	res.bc = NULL;
	res.updated = 1;
	res.r[0] = START_FOOD;
	while (i < 7)
	{
		res.r[i] = 0;
		i++;
	}
	res.dir = (rand() % 4) * (M_PI / 2);
	res.cs = cs;
	res.lvl = 1;
	res.timer = 0;
	res.what = 0;
	res.team = 0;
	return (res);
}

t_pl		new_pl(t_env *e, t_egg egg)
{
	t_pl	res;

	(void)e;
	res.x = egg.x;
	res.y = egg.y;
	e->map.map[egg.y][egg.y].plonit++;
	res.action = 0;
	res.actionwait = 0;
	res.bc = NULL;
	res.updated = 1;
	res.r[0] = START_FOOD;
	res.dir = (rand() % 4) * (M_PI / 2);
	res.cs = -1;
	res.lvl = 1;
	res.timer = 0;
	res.what = 0;
	res.team = 0;
	return (res);
}

void	rand_generate(t_env *e)
{
	static int	seed = 0;
	int			i;
	int			seednb;
	int			seedx;
	int			seedy;
	int			seedr;

	srand(seed);
	seed += 3;
	seednb = rand() % 9; //faire apres que ce soit plutot en rapport avec la taille terrain
	while (i < seednb)
	{
		seedx = rand() % e->map.xlen;
		seedy = rand() % e->map.ylen;
		seedr = rand() % NBRESSOURCE;
		e->map.map[seedy][seedx].r[seedr] += i % 2;
		i++;
	}
	return ;
}

void		serv_update(t_env *e)
{
	int		i;
	char	*res;
	time_t	tloc;

	i = 0;
	while (i < e->nbpl)
	{
		ft_putstr("PB[1]");
		if (e->pl[i].action && e->pl[i].actionwait)
		{
			if (time(&tloc) - e->pl[i].timer
				> (getacttime(e->pl[i].action) / e->time_unit))
			{
				write(1, "load_function", 13);
				load_function(e->pl[i].action, i, e);
				e->pl[i].action = 0;
				e->pl[i].actionwait = 0;
			}
		}
		if (e->pl[i].updated)
		{
			g_send_pl(e->pl[i], i, e);
			e->pl[i].updated = 0;
		}
		i++;
	}
	write(1, "okpl", 4);
	if (e->map.updated)
		g_send_map(e);
	ft_putstr(ft_itoa(e->nbpl));
	ft_putstr("map");
	i = e->nbegg;
	while (i > 0)
	{
		write(1, "PB[2]", 2);
		if (e->eggs[i].updated)
		{
			g_send_egg(e->eggs[i], e->eggs[i].pl, i, e);
			e->eggs[i].updated = 0;
		}
		if (time(&tloc) - e->eggs[i].timer > (EGG_TIME / e->time_unit)
			&& !e->eggs[i].used)
		{
			e->fork = (int *)realloc(e->fork, (sizeof(int) * (e->forknb + 1)));
			e->fork[e->forknb] = e->nbpl;
			res = ft_strclone("eht #");
			res = ft_stradd(res, ft_itoa(i));
			free(res);
			res = NULL;
			e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
			e->pl[e->nbpl] = new_pl(e, e->eggs[i]);
			e->pl[e->nbpl].cs = -1;
			e->pl[e->nbpl].updated = 1;
			e->map.map[e->eggs[i].y][e->eggs[i].x].egg--;
			e->nbpl++;
			e->forknb++;
			e->eggs[i].used = 1;
		}
		i--;
	}
	ft_putstr("okegg");
	ft_putstr("WPL:");
	ft_putstr(ft_itoa(e->wpl));
	ft_putstr("<<<");
	i = e->wpl - 1;
	ft_putstr(ft_itoa(e->wpl));
	while (i >= 0)
	{
		write(1, "wpl", 3);
		if (e->forknb > 0)
		{
			ft_putstr("forknb");
			e->fds[e->waitingpl[i]].pl = e->fork[e->forknb];
			e->pl[e->fork[e->forknb]].cs = e->waitingpl[i];
			e->wpl--;
			e->forknb--;
		}
		else if (!e->fds[e->waitingpl[i]].noteam)
		{
			ft_putstr("\n\t\tJ AI UNE TEAM PUTAIN\t");
			ft_putstr(ft_itoa(e->fds[e->waitingpl[i]].team));
			ft_putstr("<<<\n\n\n");
			if (e->teams[e->fds[e->waitingpl[i]].team].nbpl < BEGINING_PL)
			{
				ft_putstr("newpl");
				ft_putstr(ft_itoa(e->waitingpl[i]));
				ft_putstr("|>");
				e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
				e->fds[e->waitingpl[i]].pl = e->nbpl;
				ft_putstr(ft_itoa(e->fds[e->waitingpl[i]].pl));
				e->pl[e->fds[e->waitingpl[i]].pl] = new_tpl(e, e->waitingpl[i]);
				e->nbpl++;
				e->tnbpl++;
				e->teams[e->fds[e->waitingpl[i]].team].nbpl++;
				e->wpl--;
			}
		}
		i--;
	}
	ft_putstr("okfork");
	if (time(&tloc) - e->generation_timer > (GENE_TIME / e->time_unit))
	{
		rand_generate(e);
		e->generation_timer = time(&tloc);
	}
	return ;
}
/*e->fork = (int *)realloc(e->fork, (sizeof(int) * (e->forknb + 1)));
	e->fork[e->forknb] = e->nbpl;
	e->pl = (t_pl *)realloc(e->pl, (sizeof(t_pl) * (e->nbpl + 1)));
	e->pl[e->nbpl] = new_pl(e, cs);
	e->pl[e->nbpl].cs = -1;
	e->nbpl++;
	e->forknb++;*/
void	main_loop(t_env *e)
{
	while (1)
	{
		ft_putstr("E->NBPL:");
		ft_putstr(ft_itoa(e->nbpl));
		ft_putstr("<<");
		//write(1, "PUTAIN1", 7);
		init_fd(e);
		//write(1, "PUTAIN2", 7);
		do_select(e);
		//write(1, "PUTAIN3", 7);
		check_fd(e);
		//write(1, "PUTAIN4", 7);
		//write(1, "HEY", 3);
		//ft_putstr("nbpl0:");
		//ft_putstr(ft_itoa(e->nbpl));
		ft_putstr("E->NBPL2:");
		ft_putstr(ft_itoa(e->nbpl));
		ft_putstr("<<");
		serv_update(e);
		ft_putstr("E->NBPL3:");
		ft_putstr(ft_itoa(e->nbpl));
		ft_putstr("<<");
		ft_putstr("\n\n");
		//ft_putstr("nbpl1:");
		//ft_putstr(ft_itoa(e->nbpl));
		//write(1, "PUTAIN5", 7);
	}
}
