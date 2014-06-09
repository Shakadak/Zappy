/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 04:06:06 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/18 04:06:07 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include "libft.h"
# include <netdb.h>
# define JOIN 4
# define NICK 3
# define WHO 2
# define ALL 5
# define MSG 6
# define RESET (7)
# define SET_OLD_PWD (6)
# define SET (5)
# define SETCWD (8)
# define GET_OLD_PWD (9)
# define BUFFSIZE (15500)
# define GET ('g')
# define PUT ('p')
# define PWD ('w')
# define LS ('l')
# define QUIT ('q')
# define CD ('c')

typedef struct				s_pwd
{
	char					*pwd;
	char					*cwd;
	char					*oldpwd;

}							t_pwd;

typedef struct				s_servaddress
{
	int						i;
	int						j;
	int						port;
	char					*nbr;
	char					*ip;
}							t_servaddress;

int							getcdpath_(char *path);
void						fork_connection(int sock);
char						*get_data_from_socket(int sock);
void						send_data_to_socket(int sock, char *data, int len);
void						send_file_to_socket(int sock, char *filename);
void						send_file(int sock);
void						get_file_from_socket(int sock, char *filename);
void						get_file(int sock);
void						ft_putsstr(char **sstr);
char						*ft_cd(char *path);
char						*ft_ls(void);
char						*ft_pwd(int arg, char *newpwd);
char						*ft_trim(char *str);
int							lenuntiltrimchar(char *str);
void						handlerfinfils (int sig);
t_servaddress				get_serv_address(void);
int							cmdfound(char *cmd, char *message, int socket_desc);
void						select_cmd(char *message, int socket_desc);
int							ft_handle_who(char *none, int socket_desc);
int							ft_handle_msg(char *nickmsg, int socket_desc);
int							ft_handle_join(char *chan, int socket_desc);
int							ft_handle_nick(char *nickname, int socket_desc);
int							ft_handle_all(char *message, int socket_desc);

#endif
