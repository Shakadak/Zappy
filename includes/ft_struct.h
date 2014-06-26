/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:51:05 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:51:45 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct		s_queue
{
	void			*data;
	struct s_queue	*next;
	struct s_queue	*tail;
}					t_queue;

typedef struct		s_raw
{
	int				range_start;
	int				range_end;
	int				center;
}					t_raw;

typedef struct		s_stones
{
	int				linemate;
	int				deraumere;
	int				sibure;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_stones;

typedef struct		s_inventory
{
	int				life;

}					t_inventory;

typedef struct		s_step
{
	int				needed_players;
	t_stones		needed_stones;
}					t_step;

typedef struct		s_env
{
	int				x;
	int				y;
	int				nb_connect;
	int				level;
	char			*team;
	pid_t			id;
	t_inventory		inventory;
	t_step			steps[8];
	t_queue			*actions;
	t_queue			*waits;
	fd_set			write_fds;
	fd_set			read_fds;
	t_raw			vision[8];
	int				state;
}					t_env;

#endif
