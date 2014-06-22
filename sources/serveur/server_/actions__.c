/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions__.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 19:00:14 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 19:00:16 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

int						prepare_see(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = SEE;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						prepare_inv(t_env *e, int cs)
{
	e->pl[e->fds[cs].pl].actionwait = 1;
	e->pl[e->fds[cs].pl].action[e->pl[e->fds[cs].pl].cact] = INV;
	e->pl[e->fds[cs].pl].cact++;
	return (1);
}

int						aff_inv(t_env *e, int pl)
{
	int					i;
	int					j;
	char				*res;

	i = 0;
	j = 0;
	res = ft_strclone("{");
	while (j < NBRESSOURCE)
	{
		if (e->pl[pl].r[j] > 0)
		{
			if (i)
				res = ft_stradd(res, ", ");
			res = ft_stradd(res, getressource(j));
			res = ft_stradd(res, " ");
			res = ft_straddrp(res, ft_itoa(e->pl[pl].r[j]));
			i = 1;
		}
		j++;
	}
	res = ft_stradd(res, "}");
	send_res(pl, res, e);
	free(res);
	res = NULL;
	return (1);
}

int						get_what(char *buf)
{
	if (!ft_strcmp(buf, "linemate"))
		return (LINEMATE);
	if (!ft_strcmp(buf, "deraumère"))
		return (DERAUMERE);
	if (!ft_strcmp(buf, "sibur"))
		return (SIBUR);
	if (!ft_strcmp(buf, "mendiane"))
		return (MENDIANE);
	if (!ft_strcmp(buf, "phiras"))
		return (PHIRAS);
	if (!ft_strcmp(buf, "thystame"))
		return (THYSTAME);
	if (!ft_strcmp(buf, "nourriture"))
		return (NOURRITURE);
	return (-1);
}
