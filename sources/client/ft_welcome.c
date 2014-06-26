/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:42:18 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:45:30 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_push_go_up(int len, t_env *e)
{
	int		i;

	i = 0;
	while (i < len)
	{
		e->actions = ft_queue_push(e->actions, ft_strdup("avance"));
		i++;
	}
	return (i);
}

void	ft_end(t_env *e, char *buf_to_del, t_tcpsock *server, const char *msg)
{
	void		*data;

	ft_strdel(&buf_to_del);
	while ((data = ft_queue_pop(&e->actions)))
		ft_memdel(&data);
	while ((data = ft_queue_pop(&e->waits)))
		ft_memdel(&data);
	ft_fatal((char *)msg);
	ftsock_destroy(&server);
}

void	ft_welcome(t_env *e, t_tcpsock *server)
{
	char	*recv;
	char	**split;

	ft_putendl_fd(e->team, server->sock);
	if (get_next_line(server->sock, &recv) <= 0)
		ft_end(e, NULL, server, "not enough space.");
	if (ft_strequ(recv, "ko"))
		ft_end(e, recv, server, "bad team");
	e->nb_connect = ft_atoi(recv);
	ft_strdel(&recv);
	get_next_line(server->sock, &recv);
	split = ft_strsplit(recv, ' ');
	e->x = ft_atoi(split[0]);
	e->y = ft_atoi(split[1]);
	ft_split_destroy(split);
}
