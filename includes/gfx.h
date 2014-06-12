/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvincent <jvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 17:52:56 by jvincent          #+#    #+#             */
/*   Updated: 2014/06/12 18:15:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include "gfx_struct.h"
# include "gfx-net.h"

/*
** gfx.c
*/
int			gfx_core(t_env *gfx);

/*
** draw.c
*/
void		draw_menu(t_env *gfx);
void		draw_board(t_env *gfx);

/*
** event.c
*/
int			zoom_in(t_env *gfx);
int			zoom_out(t_env *gfx);
int			event_listener(SDL_Event *ev, int *quit, t_env *gfx);

/*
** mouse.c
*/
void		mouse_check_y(t_env *gfx, int y);
void		mouse_check_x(t_env *gfx, int x);
void		mouse_event(t_env *gfx);

/*
** click.c
*/
int			is_clickable(t_env *gfx, int x, int y);
int			handle_click_event(t_env *gfx, int event);
void		click_event(t_env *gfx);

/*
** direction.c
*/
int			key_update(SDL_Event *ev, int current, int dir, t_env *gfx);
int			rem_dir(int param, int dir);
int			add_dir(int param, int dir);

/*
** camera.c
*/
void		move_camera(t_env *gfx);

/*
** init.c
*/
SDL_Texture	*load_texture(t_env *gfx, char *str);
int			init_sdl(t_env *gfx);
void		close_sdl(t_env *gfx);

/*
** shm.c
*/
int			init_shm(t_env *gfx);
int			sem_lock(t_env *gfx, int lock);
int			shm_free(t_env *gfx);

#endif
