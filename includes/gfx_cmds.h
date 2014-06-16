#ifndef GFX_CMDS_H
# define GFX_CMDS_H

# include "gfx_struct.h"

void		*get_x(char *cmd);
void		*get_p(char *cmd);
t_player	*get_player(t_env *gfx, int id, char *team, t_ptype type);

void		bct(t_env *gfx, char **param);

void		ebo(t_env *gfx, char **param);
void		edi(t_env *gfx, char **param);
void		eht(t_env *gfx, char **param);
void		enw(t_env *gfx, char **param);

void		msz(t_env *gfx, char **param);

void		pbc(t_env *gfx, char **param);
void		pdi(t_env *gfx, char **param);
void		pdr(t_env *gfx, char **param);
void		pex(t_env *gfx, char **param);
void		pfk(t_env *gfx, char **param);
void		pgt(t_env *gfx, char **param);
void		pic(t_env *gfx, char **param);
void		pie(t_env *gfx, char **param);
void		pin(t_env *gfx, char **param);
void		plv(t_env *gfx, char **param);
void		pnw(t_env *gfx, char **param);
void		ppo(t_env *gfx, char **param);

void		sbp(t_env *gfx, char **param);
void		seg(t_env *gfx, char **param);
void		sgt(t_env *gfx, char **param);
void		smg(t_env *gfx, char **param);
void		suc(t_env *gfx, char **param);

void		tna(t_env *gfx, char **param);

#endif
