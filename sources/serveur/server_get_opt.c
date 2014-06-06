/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:27 by npineau           #+#    #+#             */
/*   Updated: 2014/06/06 17:22:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "serveur.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2 || !ft_isx(av[1], ft_isdigit))
	{
		fprintf(stderr, "Usage: %s port\n", av[0]);
		exit(1);
	}
	e->port = ft_atoi(av[1]);
}
