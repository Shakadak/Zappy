void	plv(t_env *gfx, char **param)
{
	t_player	*current;

	current = get_player(gfx, ft_atoi(param[1]), NULL, PLAYER);
	current->level = ft_atoi(param[2]);
}
