/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:16:08 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:16:10 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "bircd.h"
//e->eggs[] malloc int * 1;
//e->nbegg 0;

//e->map.map[][].egg 0
//				.plonit 0
//				.r[NB_RESSOURCE + 1] 0 // pui generation food etant la case 6
//e->teams malloc t_team 1
//e->teams.max 0
//e->teams.nbpl 0 
//e->pl.bc char * NULL
//e->pl.dir double? 0
//e->pl.updated 0
//e->nbpl 0;
//e->map.updated 0
//
//o pire on execute les actions d abord tt court pr le moment et on lance timer apres
//coder encore la fonction pour avoir le 5eme atoi, etc... ah nn cte pr le graphik
//partie graphique.
//loop general.
//coder aussi send_res;
//bon va ptet falloir faire des ressources temporaires du coup pour check les take
//et du coup on les modif aussi pour les incantations.
//et du coup on empeche les joueurs incantants d etre expulse basta.
/*

//fonctions:
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
//
//send.c

//client_read.c
void					send_res(int pl, char *tosend, t_env *e)
{
	int					i;
	int					j;
	int					len;
	char				tmp[4096];

	ft_putstr("J AI UN RES:");
	ft_putstr(tosend);
	ft_putstr(";;;;;");
	i = 0;
	j = 0;
	ft_putstr("\nDEBUTSENDRES\n\n\n\n");
	len = ft_strlen(tosend);
	ft_putstr("LEN:");
	ft_putstr(ft_itoa(len));
	ft_putstr("<<");
	if (pl >= 0)
	{
		while (i < len)
		{
			memcpy(tmp, tosend, 4096);
			tmp[ft_strlen(tosend)] = '\0';
			write(e->pl[pl].cs, tmp, ft_strlen(tmp));
			i+= BUF_SIZE;
		}
		memcpy(tmp, "\n", 4096);
		tmp[2] = '\0';
		write(e->pl[pl].cs, tmp, ft_strlen(tmp));
	}
	i = 0;
	//ft_putstr("E->")
	ft_putstr("\n\n\nGRAPHNB::::");
	ft_putstr(ft_itoa(e->graphnb));
	ft_putstr("LEN:");
	ft_putstr(ft_itoa(len));
	ft_putstr("PUTAIN DE 4096:");
	ft_putstr(ft_itoa(BUF_SIZE));
	ft_putstr("PUTAIN\n\n\n");
	if (pl == -1)
	{
		while (j < e->graphnb)
		{
			i = 0;
			while (i < len)
			{
				ft_putstr("PUTAIN DE I++:");
				ft_putstr(ft_itoa(i));
				ft_putstr("<<<<");
				memcpy(tmp, tosend, 4096);
				tmp[ft_strlen(tosend)] = '\0';
				ft_putstr("TMP:::");
				ft_putstr(tmp);
				write(e->graphfd[j], tmp, ft_strlen(tmp));
				usleep(45);
				i = i + BUF_SIZE;
			}
			ft_putstr("BOUCLE BOUCLEEE\n\n\n");
			memcpy(tmp, "\n", 4096);
			tmp[1] = '\0';
			write(e->graphfd[j], tmp, ft_strlen(tmp));
			tmp[0] = '\0';
			j++;
		}
	}
	ft_putstr("\nFINNNNNNSENDRES\n\n\n\n");
	return ;
}

int						connect_graphic(t_env *e, int cs)
{
	//e->pl[e->fds[cs].pl].graph = 1;
	e->fds[cs].pl = -1;
	e->graphfd = (int *)realloc(e->graphfd, (sizeof(int) * (e->graphnb + 1)));
	e->graphfd[e->graphnb] = cs;
	e->graphnb++;
	init_graph(e, cs);
	return (1);
}

int						search_team(char *buf, t_env *e)
{
	int					i;
	int					check;

	i = 0;
	check = 0;
	while (i < e->nbteam)
	{
		if (!ft_strncmp(buf, e->teams[i].name, ft_strlen(e->teams[i].name)))
		{
			check++;
			return (i);
		}
		i++;
	}
	e->teams = (t_team *)realloc(e->teams, (sizeof(t_team) * (e->nbteam + 1)));
	if (!check)
	{
		e->teams[e->nbteam].nbpl = 0;
		e->teams[e->nbteam].name = ft_strclone(buf);
		e->teams[e->nbteam].nbpl++;
		e->nbteam++;
	}
	return (e->nbteam - 1);
}

int						foundop(char *tmp, char *buf, t_env *e, int cs)
{
	time_t				tloc;

	tloc = 0;
	//write(1, "FOUNDOP", 6);
	if (e->fds[cs].pl >= 0 && !e->fds[cs].noteam)
	{
	ft_putstr("FCTREAD:");
	ft_putstr("BUF[");
	ft_putstr(buf);
	ft_putstr("] pl:{");
	ft_putstr(ft_itoa(e->fds[cs].pl));
	ft_putstr("} cs:");
	ft_putstr(ft_itoa(cs));
	ft_putstr("] actionwait:[");
	ft_putstr(ft_itoa(e->pl[e->fds[cs].pl].actionwait));
	ft_putstr("]< x: ");
	ft_putstr(ft_itoa(e->pl[e->fds[cs].pl].x));
	ft_putstr(";; y: ");
	ft_putstr(ft_itoa(e->pl[e->fds[cs].pl].y));
	ft_putstr("<<<");
	ft_putstr("DIR:");
	ft_putstr(ft_itoa(e->pl[e->fds[cs].pl].dir));
	if (e->fds[cs].pl >= 0 && !e->fds[cs].noteam)
	{
		if (!e->pl[e->fds[cs].pl].actionwait)
		{
			ft_putstr("foundop");
			if (!ft_strcmp(tmp, "avance"))
			{
				ft_putstr(">>>>>>>>>>>>>>>avance<<<<<<<<<<<<<<<");
				prepare_move(FW, e, cs);
			}
			if (!ft_strcmp(tmp, "droite"))
			{
				ft_putstr(">>>>>>>>>>>>>>>>droite<<<<<<<<<<<<<<");
				prepare_move(R, e, cs);
			}
			if (!ft_strcmp(tmp, "gauche"))
			{
				ft_putstr(">>>>>>>>>>>>>>>>gauche<<<<<<<<<<<<<<");
				prepare_move(L, e, cs);
			}
			if (!ft_strcmp(tmp, "voir"))
			{
				ft_putstr(">>>>>>>>>>>voir<<<<<<<<<<s");
				prepare_see(e, cs);
			}
			if (!ft_strcmp(tmp, "inventaire"))
			{
				ft_putstr(">>>>>>inventaire<<<<");
				prepare_inv(e, cs);
			}
			if (!ft_strcmp(tmp, "prend "))
			{
				ft_putstr(">>>>>>>>>>>>>>>>prend<<<<<<<<<<<<<<<");
				prepare_take(&buf[6], e, cs);
			}
			if (!ft_strcmp(tmp, "pose "))
			{
				ft_putstr(">>>>>>>>>>>>>>>>pose<<<<<<<<<<<<<<<<");
				prepare_drop(&buf[5], e, cs);
			}
			if (!ft_strcmp(tmp, "expulse"))
			{
				ft_putstr(">>>>>>>>>>>>>>>>expulse<<<<<<<<<<<<<");
				prepare_eject(e, cs);
			}
			if (!ft_strcmp(tmp, "broadcast "))
			{
				ft_putstr(">>>>>>>>>>>>>>>>broadcast<<<<<<<<<<<");
				prepare_broadcast(&buf[10], e, cs);
			}
			if (!ft_strcmp(tmp, "incantation"))
			{
				ft_putstr(">>>>>>>>>>>>>>>>incantation<<<<<<<<<");
				incantation(e, cs);
			}
			if (!ft_strcmp(tmp, "fork"))
			{
				ft_putstr(">>>>>>>>>>>>>>>>fork<<<<<<<<<<<<<<<");
				fork_player(e, cs);
			}
			if (!ft_strcmp(tmp, "connect_nbr"))
			{
				ft_putstr("connect_nbr");
				connect_nbr(e, cs);
			}
			if (!ft_strcmp(tmp, "cp "))
			{
				change_pos(&buf[3], e, cs);
			}
			e->pl[e->fds[cs].pl].timer = time(&tloc);
	}
	}
	}
	else if (!ft_strcmp(tmp, "GRAPHIC"))
	{
		ft_putstr("GRAPHIC<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
		connect_graphic(e, cs);
		e->fds[cs].pl = -2;
		return (1);
	}
	else
		return (-1);
	return (-1);
}

int						lenuntil(char *str, char c)
{
	int					i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int						get_opt_(char *buf, t_env *e, int cs)
{
	int					i;
	char				*tmp;

	tmp = (char *)malloc(sizeof(char) * (lenuntil(buf, ' ') + 1));
	i = 0;
	while (buf[i] != '\0')
	{
		tmp[i] = buf[i];
		tmp[i + 1] = '\0';
		if (foundop(tmp, buf, e, cs) != -1)
			break ;
			//return (foundop(tmp, buf, e, cs));
		i++;
	}
	if (e->fds[cs].noteam == 1 && e->fds[cs].pl >= -1)
	{
		ft_putstr("noteam");
		//e->waitingpl = (int *)realloc(e->waitingpl, sizeof(int) * (e->wpl + 1));
		//e->waitingpl[e->wpl - 1] = cs;
		e->fds[cs].team = search_team(buf, e);
		e->fds[cs].noteam = 0;
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

void					client_read(t_env *e, int cs)
{
	int					r;

	ft_putstr("putain de merde");
	r = recv(cs, &e->fds[cs].buf_read, 4096, 0);
	if (r <= 0)
	{
		ft_putstr("client disconnected");
		e->fds[cs].type = FD_FREE;
		e->map.map[e->pl[e->fds[cs].pl].y][e->pl[e->fds[cs].pl].x].plonit--;
		e->pl[e->fds[cs].pl].team = -1;
		e->tnbpl--;
		e->fds[cs].pl = -1;
	}
	else
	{
		ft_putstr("putain de merde");
		get_opt_(e->fds[cs].buf_read, e, cs);
	}
	return ;
}
