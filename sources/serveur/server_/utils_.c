/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/22 20:14:53 by gdefrait          #+#    #+#             */
/*   Updated: 2014/06/22 20:14:55 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bircd.h"

void					send_res(int pl, char *tosend, t_env *e)
{
	int					j;

	j = 0;
	if (pl >= 0)
	{
		write(e->pl[pl].cs, tosend, ft_strlen(tosend));
		write(e->pl[pl].cs, "\n", 1);
	}
	if (pl == -1)
	{
		while (j < e->graphnb)
		{
			if (e->graphfd[j] >= 0)
			{
				write(e->graphfd[j], tosend, ft_strlen(tosend));
				write(e->graphfd[j], "\n", 1);
				j++;
			}
		}
	}
	return ;
}

int						connect_graphic(t_env *e, int cs)
{
	e->fds[cs].pl = -1;
	e->graphfd = (int *)realloc(e->graphfd, (sizeof(int) * (e->graphnb + 1)));
	e->graphfd[e->graphnb] = cs;
	e->graphnb++;
	init_graph(e, cs);
	return (1);
}

int						search_team(char *buf, t_env *e, int cs)
{
	int					i;

	i = 0;
	while (i < e->nbteam)
	{
		if (!ft_strncmp(buf, e->teams[i].name, ft_strlen(e->teams[i].name)))
			return (i);
		i++;
	}
	e->fds[cs].noteam = 1;
	return (0);
}

void					team_view(t_env *e, int cs)
{
	int					i;
	char				*res;

	i = 0;
	res = NULL;
	while (i < e->nbteam)
	{
		res = ft_strclone("NAME:");
		res = ft_stradd(res, e->teams[i].name);
		res = ft_stradd(res, "\nforks:");
		res = ft_straddrp(res, ft_itoa(e->teams[i].forknb));
		res = ft_stradd(res, "VOTRE TEAM:");
		res = ft_stradd(res, e->teams[e->fds[cs].team].name);
		send_res(e->fds[cs].pl, res, e);
		free(res);
		res = NULL;
		i++;
	}
}
