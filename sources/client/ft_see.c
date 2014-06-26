/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:37:39 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:41:51 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_track_target(int numcase, int line, t_env *e)
{
	int		move_up;
	int		move_side;
	int		counter;

	counter = 0;
	move_up = line + 1;
	move_side = numcase - e->vision[line].center;
	counter += ft_push_go_up(move_up, e);
	if (move_side < 0)
		e->actions = ft_queue_push(e->actions, ft_strdup("gauche"));
	else if (move_side > 0)
		e->actions = ft_queue_push(e->actions, ft_strdup("droite"));
	if (move_side != 0)
		counter++;
	move_side = ft_abs(move_side);
	counter += ft_push_go_up(move_side, e);
	return (counter);
}

int		ft_track(int numcase, t_env *e)
{
	int		i;
	int		start;
	int		end;
	int		line;

	if (numcase == 0)
	{
		e->actions = ft_queue_push(e->actions, ft_strdup("prend nourriture"));
		return (1);
	}
	i = 0;
	line = -1;
	while (i < 8 && line == -1)
	{
		start = e->vision[i].range_start;
		end = e->vision[i].range_end;
		if (numcase >= start && numcase <= end)
			line = i;
		i++;
	}
	if (line != -1)
		return (ft_track_target(numcase, line, e));
	return (0);
}

int		ft_look_for(t_env *e, char **split, t_tcpsock *server, const char *obj)
{
	int		presence;
	int		i;

	presence = 0;
	i = 0;
	while (split[i])
	{
		if (split[i] && *split[i] && ft_strstr(split[i], obj) != NULL)
		{
			presence = 1;
			if (ft_track(i, e))
				FD_SET(server->sock, &e->write_fds);
			break ;
		}
		i++;
	}
	return (presence);
}

void	ft_see(char *recv_buf, t_env *e, t_tcpsock *server)
{
	void	*action;
	char	**split;
	int		presence;

	if (e->waits == NULL)
		ft_fatal("'ok' received, but nothing is in the waitings queue.");
	action = ft_queue_pop(&e->waits);
	recv_buf[ft_strlen(recv_buf) - 1] = 0;
	recv_buf++;
	split = ft_strsplit_strict(recv_buf, ',');
	presence = 0;
	if (e->state == STATE_HUNGRY)
		presence = ft_look_for(e, split, server, "nourriture");
	ft_split_destroy(split);
	ft_memdel(&action);
	if (!presence)
	{
		ft_push_go_up(e->level, e);
		FD_SET(server->sock, &e->write_fds);
	}
}

void	ft_inventory(char *recv_buf, t_env *e)
{
	void	*action;
	char	**split;

	if (e->waits == NULL)
		ft_fatal("'ok' received, but nothing is in the waitings queue.");
	action = ft_queue_pop(&e->waits);
	recv_buf[ft_strlen(recv_buf) - 1] = 0;
	recv_buf++;
	split = ft_strsplit_strict(recv_buf, ',');
	e->inventory.life = ft_atoi(ft_strchr(split[0], ' ') + 1);
	if (e->inventory.life < 8 && e->state != STATE_HUNGRY)
	{
		ft_putendl("STATE : HUNGRY");
		e->state = STATE_HUNGRY;
	}
	else if (e->inventory.life > 30 && e->state != STATE_FARM)
	{
		ft_putendl("STATE : FARM");
		e->state = STATE_FARM;
	}
	ft_split_destroy(split);
	ft_memdel(&action);
}
