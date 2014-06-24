/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bircd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 06:07:38 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 06:07:39 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIRCD_H
# define BIRCD_H

# include <sys/select.h>
# include <math.h>
# include <time.h>
# include "libft.h"
# include "ftp.h"

# define			BEGINING_PL 12
# define			WACT 10
# define			GENE_TIME 4
# define			START_FOOD 80
# define			FD_FREE	0
# define			EGG_TIME 600
# define			FD_SERV	1
# define			FD_CLIENT	2
# define			BUF_SIZE	4096
# define			WACT 10
# define			JOIN 4
# define			NICK 3
# define			WHO 2
# define			ALL 5
# define			MOVELEFT 89
# define			MOVERIGHT 90
# define			MOVEFW 91
# define			MSG 6
# define			MOVE (5)
# define			SEE (78)
# define			STANDARD_MAXPL (75)
# define			STANDARD_T (26)
# define			STANDARD_PORT (9999)
# define			STANDARD_XLEN (35)
# define			STANDARD_YLEN (35)
# define			EJECTPOWA (2)
# define			NOURRITURE (0)
# define			LINEMATE (1)
# define			DERAUMERE (2)
# define			SIBUR (3)
# define			MENDIANE (4)
# define			PHIRAS (5)
# define			THYSTAME (6)
# define			TAKE (6)
# define			DROP (7)
# define			EJECT (8)
# define			L (5)
# define			R (9)
# define			FW (7)
# define			FORK (9)
# define			INCANTATION (10)
# define			CNB (11)
# define			NBRESSOURCE (7) // check pour la nourriture pb
# define			BROADCAST (12)
# define			LVLUP (13)
# define			INV (14)
# define			UP (M_PI / 2)
# define			DOWN ((3 * M_PI) / 2)
# define			LEFT (M_PI)
# define			RIGHT (0)
# define			Xv(err,res,str)	(x_void(err,res,str))
# define			X(err,res,str)		(x_int(err,res,str))
# define			MAX(a,b)	((a > b) ? a : b)
# define			USAGE		"Usage: %s port\n"

typedef struct		s_fd
{
	int				type;
	char			*chan;
	char			*nick;
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
	int				nicktrue;
	int				pl;
	int				noteam;
	int				team;
}					t_fd;

typedef struct		s_fdc
{
	int				fd;
	char			buf_read[BUF_SIZE + 1];
	char			buf_write[BUF_SIZE + 1];
}					t_fdc;

typedef struct		s_case
{
	int				plonit;
	int				egg;
	int				r[7];
	int				tmpr[7];
}					t_case;

typedef struct		s_map
{
	t_case			**map;
	int				xlen;
	int				ylen;
	int				updated;
}					t_map;

typedef struct		s_pl
{
	int				graph;
	int				r[7];
	int				action[WACT + 1];
	int				actionwait;
	int				alive;
	char			*bc;
	int				x;
	int				y;
	int				updated;
	int				lrf;
	int				dir;
	int				cs; //check bien init
	int				lvl;
	time_t			timer;
	int				what;
	int				cact;
	int				team; //idem
}					t_pl;

typedef struct		s_team
{
	int				nbpl;
	char			*name;
	int				*fork;
	int				forknb;
}					t_team;

typedef struct		s_egg
{
	int				updated;
	int				x;
	int				y;
	time_t			timer;
	int				used;
	int				pl;
}					t_egg;

typedef struct		s_env
{
	time_t			generation_timer;
	t_fd			*fds;
	int				port;
	int				maxfd;
	int				max;
	int				r;
	fd_set			fd_read;
	fd_set			fd_write;
	int				servsocket;
	struct s_alpha	*nicknames;
	t_map			map;
	t_egg			*eggs; //(juste .x .y et .time)
	int				nbegg;
	t_team			*teams;
	t_pl			*pl;
	int				maxpl;
	int				time_unit;
	int				nbpl;
	int				*graphfd;
	int				graphnb;
	int				nbteam;
	int				*waitingpl;
	int				wpl;
	int				*fork;
	int				forknb;
	int				tnbpl;
	time_t			general_timer;
	char			**debug;
}					t_env;

void				broadcast___(t_env *e, int i, int pl, int x);
void				broadcast__(t_env *e, int i, int pl);
int					broadcast_(t_env *e, int pl);
int					change_pos(char *buf, t_env *e, int cs);
void				send_res(int pl, char *tosend, t_env *e);
int					cmdfound(char *cmd, char *message, int socket_desc);
void				select_cmd(char *message, int socket_desc);
void				read_zero(t_env *e, int i);
void				read_socket(t_env *e, int i);
void				who_is_here(t_env *e, int cs);
void				send_msg(t_env *e, int cs);
void				send_to_all(t_env *e, int cs);
void				joinchan(t_env *e, int cs);
void				recnick(t_env *e, int cs);
void				ft_putsstr(char **sstr);
char				*concatenate(char **sstr, char c);
void				init_env(t_env *e, char **argv);
void				get_opt(t_env *e, int ac, char **av);
void				main_loop(t_env *e);
void				srv_create(t_env *e, int port);
void				srv_accept(t_env *e, int s);
void				client_read(t_env *e, int cs);
void				client_write(t_env *e, int cs);
void				clean_fd(t_fd *fd);
int					x_int(int err, int res, char *str);
void				*x_void(void *err, void *res, char *str);
void				init_fd(t_env *e);
void				do_select(t_env *e);
void				check_fd(t_env *e);
int					prepare_move(int lrf, t_env *e, int cs);
int					move(t_env *e, int pl);
char				*getressource(int rsc);
char				*get_case_ressource(t_case tmpc, int i, int j,
					char *res);
char				*lookoncase_(int i, t_case tmpc, char *res);
char				*lookoncase(t_env *e, int yc, int xc, int number);
char				*check_cases_h(t_env *e, int y, int x, int hm);
char				*check_cases_v(t_env *e, int y, int x, int hm);
char				*seecaselvl(int lvl, int pl, t_env *e);
int					see(t_env *e, int pl);
int					prepare_see(t_env *e, int cs);
int					prepare_inv(t_env *e, int cs);
int					aff_inv(t_env *e, int pl);
int					get_what(char *buf);
int					prepare_take(char *buf, t_env *e, int cs);
int					take(t_env *e, int pl);
int					prepare_drop(char *buf, t_env *e, int cs);
int					drop(t_env *e, int pl);
int					prepare_eject(t_env *e, int cs);
int					prepare_broadcast(char *buf, t_env *e, int cs);
int					getdir(double x, double y, int pl, t_env *e);
int					send_bc_to_pl(int pl, int dir, char *tosend, t_env *e);
int					check_ressources(int *ressources, int x, int y, t_env *e);
int					incantation_(int nbpl, int *ressources, t_env *e,
					int pl);
int					lvl_up(t_env *e, int pl);
int					incantation(t_env *e, int pl);
int					prepare_incantation(t_env *e, int cs);
int					prepare_fork(t_env *e, int cs);
int					connect_nbr(t_env *e, int cs);
int					foundop(char *tmp, char *buf, t_env *e, int cs);
int					get_opt_(char *buf, t_env *e, int cs);
void				load_function(int action, int pl, t_env *e);
void				serv_update(t_env *e);
void				init_graph(t_env *e, int cs);
int					fork_player(t_env *e, int pl);
int					getteams(t_env *e, char **argv, int j);
void				add_args(t_env *e, char **argv);
int					getrc(int n, char xy, t_env *e);
int					move_(t_env *e, int pl, int lrf);
int					getnumb(char *str, int n, char c);
char				*check_cases_down(t_env *e, int y, int x, int hm);
char				*check_cases_up(t_env *e, int y, int x, int hm);
char				*check_cases_left(t_env *e, int y, int x, int hm);
char				*check_cases_right(t_env *e, int y, int x, int hm);
void				aff_map___(char **toaff, t_env *e);
void				prepare_debug(int i, t_env *e);
double				square(double nbr);
void				eject_(int j, int pl, t_env *e);
void				eject__(int pl, t_env *e);
int					eject(t_env *e, int pl);
double				getdir_(double x, double y, double norm, int dir);
int					check_ressources(int *ressources,
	int x, int y, t_env *e);
void				incantation_pl(char **res, char **tograph, t_env *e,
	int pl);
int					incantation_(int nbpl, int *ressources, t_env *e,
	int pl);
void				g_send_pl(t_pl pl, int i, t_env *e);
void				g_send_case(t_case c, int x, int y, t_env *e);
void				g_send_map(t_env *e);
void				g_send_egg(t_egg egg, int pl, int eggnb, t_env *e);
void				load_function_(int action, int pl, t_env *e);
int					getacttime(int action);
void				init_graph_(t_env *e, int i);
void				init_food(t_pl *pl);
void				new_tpl(t_env *e, int cs, int newpl, t_pl *res);
t_pl				new_pl(t_env *e, t_egg egg, int id);
void				check_pl_(t_env *e, int i, int tmp, time_t tloc);
void				check_pl(int *check, t_env *e, int i, int tmp);
void				check_wpl(t_env *e, int i, int tmp);
void				rand_generate(t_env *e);
void				serv_update__(t_env *e, int tmp, int i, time_t tloc);
void				serv_update_(t_env *e, int tmp, int i, time_t tloc);
int					connect_graphic(t_env *e, int cs);
int					search_team(char *buf, t_env *e, int cs);
void				team_view(t_env *e, int cs);

#endif
