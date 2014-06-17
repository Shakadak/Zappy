void	pie(t_env *gfx, char **param)
{
	int	pos;

	pos = ft_atoi(param[1]) + ft_atoi(param[2]) * gfx->msize[0];
	if (ft_atoi(param[3]))
		gfx->g->map[pos]->action = SUCCESS;
	else
		gfx->g->map[pos]->action = FAIL;
}
