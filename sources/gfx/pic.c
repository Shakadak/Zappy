void	pic(t_env *gfx, char **param)
{
	int			i;
	t_player	*current;

	i = 4;
	while (param[i])
	{
		current = get_player(gfx, ft_atoi(param[i]), NULL, PLAYER);
		i++;
	}
}
