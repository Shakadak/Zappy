/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:04:30 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/22 21:30:15 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/stat.h>
# include <netdb.h>

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef struct				s_connect
{
	int						read_size;
	int						socket_desc;
	int						client_sock;
	int						c;
	struct sockaddr_in		serv;
	struct protoent			*proto;
	struct sockaddr_in		client;
}							t_connect;

typedef struct				s_count
{
	int						len;
	char					*file;
	char					nbbuf[10];
	int						fd;
	int						i;
	int						j;
	int						k;
	int						l;
	char					c;
	int						check;
	int						index;
	int						res;
}							t_count;

typedef struct				s_alpha
{
	struct s_alpha			*a;
	struct s_alpha			*b;
	struct s_alpha			*c;
	struct s_alpha			*d;
	struct s_alpha			*e;
	struct s_alpha			*f;
	struct s_alpha			*g;
	struct s_alpha			*h;
	struct s_alpha			*i;
	struct s_alpha			*j;
	struct s_alpha			*k;
	struct s_alpha			*l;
	struct s_alpha			*m;
	struct s_alpha			*n;
	struct s_alpha			*o;
	struct s_alpha			*p;
	struct s_alpha			*q;
	struct s_alpha			*r;
	struct s_alpha			*s;
	struct s_alpha			*t;
	struct s_alpha			*u;
	struct s_alpha			*v;
	struct s_alpha			*w;
	struct s_alpha			*x;
	struct s_alpha			*y;
	struct s_alpha			*z;
	struct s_alpha			*big_up;
	struct s_alpha			*hold_up;
	struct s_alpha			*digimone;
	struct s_alpha			*digimtwo;
	struct s_alpha			*digimthree;
	struct s_alpha			*digimfour;
	struct s_alpha			*digimfive;
	struct s_alpha			*digimsix;
	struct s_alpha			*low_down;
	char					*val;
	int						mid;
}							t_alpha;

typedef struct				s_okey
{
	char					*key;
	char					*okey;

}							t_okey;

char						*getuntil(char c, char *str);
void						ft_bzero(void *s, size_t n);
int							ft_atoi(const char *nptr);
size_t						ft_strlen(const char *s);
char						*ft_strdup(const char *s1);
char						*ft_strcpy(char *dest, const char *src);
char						*ft_strncpy(char *dest, const char *src, size_t n);
char						*ft_strcat(char *dest, const char *src);
char						*ft_strncat(char *dest, const char *src, size_t n);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *s1, const char *s2);
char						*ft_strnstr(const char *s1, const char *s2,
							size_t n);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, void (*f)(unsigned int,
							char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
							char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1, char const *s2,
							size_t n);
char						*ft_strsub(char const *s, unsigned int start,
							size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
void						ft_putchar_fd(char c, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
void						*ft_memcpy(void *s1, const void *s2, size_t n);
void						*ft_memccpy(void *dest, const void *src, int c,
							size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp (const void *s1, const void *s2,
							size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memset(void *s, int c, size_t n);
void						ft_putstr_fd(char const *s, int fd);
int							ft_strncmp(const char *s1, const char *s2,
							size_t n);
int							ft_strlen_const(char const *str);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
size_t						ft_strlcat(char *dest, const char *src,
							size_t size);
char						**ft_strsplit(char const *s, char c);
char						*ft_strclone(char *toclone);
char						*ft_stradd(char *s1, const char *s2);
void						ft_putsstr(char **sstr);
size_t						ft_sstrlen(char **sstr);
void						sstrmemdel(char ***todel);
void						rec(char *str, char *index, struct s_alpha *data);
char						*src(char *index, struct s_alpha *data);
t_alpha						*srcnm(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val);
char						*srchah(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val);
void						recah(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val);
t_alpha						*recnm(struct s_alpha *alpha,
							struct s_okey *key, int i, char *val);
int							is_capable(int c);
int							is_scapable(int c);
char						*getval(char *val);
char						*ft_straddrp(char *s1, char *s2);
int							lenuntil(char *str, char c);

#endif

