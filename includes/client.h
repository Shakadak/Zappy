#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include "libft.h"
# include "ftsock.h"

typedef struct		s_env
{
	int				map_x;
	int				map_y;
	int				nb_connect;
	char			*team;
	char			name[4];
}					t_env;

#endif
