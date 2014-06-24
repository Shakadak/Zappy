#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include "libft.h"
# include "ftsock.h"

typedef struct		s_env
{
	int				x;
	int				y;
	int				nb_connect;
	char			*team;
	pid_t			id;
}					t_env;

#endif
