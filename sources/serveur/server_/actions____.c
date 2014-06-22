/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions____.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:15:23 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:15:25 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						fork_player(t_env *e, int pl)
{
	time_t				tloc;
	char				*tog;

	e->map.map[e->pl[pl].y][e->pl[pl].x].egg++;
	e->eggs = (t_egg *)realloc(e->eggs, (sizeof(t_egg)) * (e->nbegg + 1));
	tog = ft_strclone("enw #");
	tog = ft_straddrp(tog, ft_itoa(e->nbegg));
	tog = ft_stradd(tog, " #");
	tog = ft_straddrp(tog, ft_itoa(pl));
	tog = ft_stradd(tog, " ");
	tog = ft_straddrp(tog, ft_itoa(e->pl[pl].x));
	tog = ft_stradd(tog, " ");
	tog = ft_straddrp(tog, ft_itoa(e->pl[pl].y));
	send_res(-1, tog, e);
	free(tog);
	tog = NULL;
	e->eggs[e->nbegg].updated = 1;
	e->eggs[e->nbegg].pl = pl;
	e->eggs[e->nbegg].x = e->pl[pl].x;
	e->eggs[e->nbegg].y = e->pl[pl].y;
	e->eggs[e->nbegg].timer = time(&tloc);
	e->eggs[e->nbegg].used = 0;
	send_res(pl, "ok", e);
	e->nbegg++;
	return (1);
}

int						prepare_fork(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = FORK;
	e->pl[e->fds[cs].pl].cact++;
	e->pl[e->fds[cs].pl].actionwait = 1;
	return (1);
}

int						connect_nbr(t_env *e, int cs)
{
	int					pl;

	pl = e->fds[cs].pl;
	if (e->teams[e->fds[e->pl[pl].cs].team].nbpl < e->maxpl)
		send_res(pl,
			ft_itoa(e->maxpl - e->teams[e->fds[e->pl[pl].cs].team].nbpl), e);
	else
		send_res(pl, ft_itoa(e->teams[e->fds[e->pl[pl].cs].team].forknb), e);
	return (1);
}
