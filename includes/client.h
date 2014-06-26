/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garm <garm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:49:29 by garm              #+#    #+#             */
/*   Updated: 2014/06/26 19:51:51 by garm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include "libft.h"
# include "ftsock.h"
# include "ft_struct.h"

# define STATE_HUNGRY 1
# define STATE_FARM 2

/*
** Main
*/
int		ft_push_go_up(int len, t_env *e);

/*
** Queues
*/
t_queue	*ft_queue_create(void *data);
t_queue	*ft_queue_push(t_queue *q, void *data);
void	*ft_queue_pop(t_queue **q);
int		ft_queue_len(t_queue *q);

/*
** Init (ft_init.c)
*/
void	ft_steps_init(t_env *e);
void	ft_step_init(t_env *e, int level, const char *format);
void	ft_inventory_init(t_env *e);
void	ft_raw_init(t_raw *raw, int range_start, int center, int range_end);
void	ft_vision_init(t_env *e);

/*
** ft_see.c
*/

int		ft_track_target(int numcase, int line, t_env *e);
int		ft_track(int numcase, t_env *e);
int		ft_look_for(t_env *e, char **split, t_tcpsock *server, const char *obj);
void	ft_see(char *recv_buf, t_env *e, t_tcpsock *server);
void	ft_inventory(char *recv_buf, t_env *e);

/*
** Welcome (ft_welcome.c)
*/
void	ft_welcome(t_env *e, t_tcpsock *server);
void	ft_end(t_env *e, char *buf_to_del, t_tcpsock *server, const char *msg);
int		ft_push_go_up(int len, t_env *e);

/*
** Extras
*/
char	**ft_strsplit_strict(const char *s, char c);

#endif
