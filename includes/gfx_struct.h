/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:05 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/25 18:43:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_STRUCT_H
# define GFX_STRUCT_H

# include <sys/select.h>
# include "libft.h"
# include "SDL.h"
# include "SDL_image.h"

# define SDL_WPU SDL_WINDOWPOS_UNDEFINED
# define FS (SDL_WINDOW_SHOWN)
# define WIDTH	1920
# define HEIGHT	1080
# define KEY_ESC	27
# define KEY_ENTER	13
# define KEY_SPACE	32
# define KEY_UP		1073741906
# define KEY_DOWN	1073741905
# define KEY_LEFT	1073741904
# define KEY_RIGHT	1073741903
# define KEY_PLUS	119
# define KEY_MINUS	115
# define UP			0x01
# define DOWN		0x02
# define LEFT		0x04
# define RIGHT		0x08
# define SHM_SIZE	4096
# define READ_BUFF	4096
# define CASE_SIZE	(sizeof(t_case))

typedef enum		e_dir
{
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4,
}					t_dir;

typedef enum		e_size
{
	W,
	H
}					t_size;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Texture		*board;
	SDL_Texture		*tiles;
	SDL_Texture		*player;
	SDL_Texture		*stones;
}					t_sdl;

typedef	enum		e_act
{
	NONE,
	GET,
	DROP,
	INCANT,
	SUCCESS,
	FAIL,
	LAY,
	DIE,
	BROADCAST,
	EXPULSE,
	MOVE,
	TURN
}					t_act;

typedef enum		e_ptype
{
	VOID,
	PLAYER,
	EGG
}					t_ptype;

typedef struct		s_player
{
	t_ptype			type;
	int				id;
	int				x;
	int				y;
	t_dir			dir;
	int				level;
	int				food;
	int				stones[6];
	unsigned int	time;
	t_act			action;
}					t_player;

typedef struct		s_team
{
	char			*name;
	t_player		players[256];
}					t_team;

typedef struct		s_net
{
	char			*ip;
	int				port;
	int				sock;
	char			buff[READ_BUFF + 1];
	fd_set			readfds;
}					t_net;

typedef struct		s_case
{
	int				stones[6];
	int				food;
	t_act			action;
}					t_case;

typedef struct		s_game
{
	t_case			*map;
	int				nb_players;
	int				nb_team;
	t_team			teams[256];
	int				time;
	char			*winner;
}					t_game;

typedef struct		s_shm
{
	int				shmid;
	int				semid;
	t_game			*shm;
}					t_shm;

typedef struct		s_env
{
	t_sdl			e;
	int				dir;
	int				camera[2];
	pid_t			net_pid;
	int				zoom;
	int				tile_h;
	int				tile_w;
	int				map_h;
	int				map_w;
	int				msize[2];
	int				s_speed;
	t_net			net;
	t_shm			shm;
}					t_env;

#endif
