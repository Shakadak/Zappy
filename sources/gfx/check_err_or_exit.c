/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_or_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:57:45 by npineau           #+#    #+#             */
/*   Updated: 2014/06/13 18:43:39 by jvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfx.h"

int		x_int(int err, int res, char *str, t_env *gfx)
{
	if (res == err)
	{
		shm_free(gfx);
		fprintf(stderr, "%s error: %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str, t_env *gfx)
{
	if (res == err)
	{
		shm_free(gfx);
		fprintf(stderr, "%s error: %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}
