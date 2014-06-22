/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions________.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:22:03 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:22:05 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						incantation_(int nbpl, int *ressources, t_env *e,
	int pl)
{
	char				*res;
	char				*tograph;

	if (e->map.map[e->pl[pl].y][e->pl[pl].x].plonit >= nbpl
		&& check_ressources(ressources, e->pl[pl].x, e->pl[pl].y, e))
	{
		tograph = ft_straddrp(ft_strclone("pic "), ft_itoa(e->pl[pl].x));
		tograph = ft_stradd(tograph, " ");
		tograph = ft_straddrp(tograph, ft_itoa(e->pl[pl].y));
		tograph = ft_stradd(tograph, " ");
		tograph = ft_straddrp(tograph, ft_itoa(e->pl[pl].lvl));
		tograph = ft_stradd(tograph, " #");
		tograph = ft_straddrp(tograph, ft_itoa(pl));
		incantation_pl(&res, &tograph, e, pl);
		send_res(-1, tograph, e);
		ft_memdel((void **)&tograph);
		res = ft_strclone("elevation en cours niveau actuel : ");
		res = ft_straddrp(res, ft_itoa(e->pl[pl].lvl + 1));
		e->pl[pl].lvl++;
		send_res(pl, res, e);
		ft_memdel((void **)&res);
	}
	return (1);
}

int						lvl_up(t_env *e, int pl)
{
	e->pl[pl].lvl += 1;
	e->pl[pl].updated = 1;
	send_res(pl, e->pl[pl].bc, e);
	return (1);
}

int						incantation(t_env *e, int pl)
{
	int					lv;
	int					*res;

	lv = e->pl[pl].lvl;
	res = NULL;
	if (lv == 1)
		res = (int [7]){0, 1, 0, 0, 0, 0, 0};
	else if (lv == 2)
		res = (int [7]){0, 1, 1, 1, 0, 0, 0};
	else if (lv == 3)
		res = (int [7]){0, 2, 0, 1, 0, 2, 0};
	else if (lv == 4)
		res = (int [7]){0, 1, 1, 2, 0, 2, 0};
	else if (lv == 5)
		res = (int [7]){0, 1, 2, 1, 3, 0, 0};
	else if (lv == 6)
		res = (int [7]){0, 1, 2, 3, 0, 1, 0};
	else if (lv == 7)
		res = (int [7]){0, 2, 2, 2, 2, 2, 1};
	else
		return (0);
	incantation_(lv - 1, res, e, pl);
	return (1);
}

int						prepare_incantation(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = INCANTATION;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].actionwait = 1;
	return (1);
}
