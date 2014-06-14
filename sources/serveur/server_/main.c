/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 03:17:04 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 03:17:05 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int			main(int ac, char **av)
{
	t_env	e;

	init_env(&e, av);
	get_opt(&e, ac, av);
	srv_create(&e, e.port);
	main_loop(&e);
	return (0);
}
