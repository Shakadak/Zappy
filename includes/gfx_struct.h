/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:53:05 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/07 16:20:17 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_STRUCT_H
# define GFX_STRUCT_H

# include "libft.h"
# include "SDL.h"
# include "SDL_image.h"

# define SDL_WPU SDL_WINDOWPOS_UNDEFINED
# define FS (SDL_WINDOW_SHOWN)
# define WIDTH 1920
# define HEIGHT 1080
# define MAP_X 100
# define MAP_Y 100
# define TILE_W 40
# define TILE_H 40
# define MAP_W (MAP_X * TILE_W)
# define MAP_H (MAP_Y * TILE_H)
# define KEY_ESC 27
# define KEY_ENTER 13
# define KEY_SPACE 32
# define KEY_UP 1073741906
# define KEY_DOWN 1073741905
# define KEY_LEFT 1073741904
# define KEY_RIGHT 1073741903

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Texture		*board;
	SDL_Texture		*tiles;
}					t_sdl;

typedef struct		s_player
{
	int				id;
	int				x;
	int				y;
	int				level;
	int				food;
	int				stones[7];
}					t_player;

typedef struct		s_team
{
	char			*name;
	t_player		*players;
}					t_team;

typedef struct 		s_env
{
	t_sdl			e;
	int				camera[2];
	int				scroll[4];
	int				s_speed;
	t_team			*teams;
}					t_env;

typedef struct		s_case
{
	int				stones[7];
	int				food;
}					t_case;

typedef struct		s_game
{
	t_case			map[MAP_W][MAP_H];
	int				nb_players;
}					t_game;

#endif
