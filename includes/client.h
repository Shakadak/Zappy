#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include "libft.h"
# include "ftsock.h"

# define STATE_HUNGRY 1
# define STATE_FARM 2

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

typedef struct		s_env
{
	int				x;
	int				y;
	int				nb_connect;
	int				level;
	int				life;
	char			*team;
	pid_t			id;
	t_queue			*actions;
	t_queue			*waits;
	fd_set			write_fds;
	fd_set			read_fds;
	t_raw			vision[8];
	int				state;
}					t_env;

/*
** Queues
*/
t_queue				*ft_queue_create(void *data);
t_queue				*ft_queue_push(t_queue *q, void *data);
void				*ft_queue_pop(t_queue **q);
int					ft_queue_len(t_queue *q);

/*
** Extras
*/
char				**ft_strsplit_strict(const char *s, char c);

#endif
