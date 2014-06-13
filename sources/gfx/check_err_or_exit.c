/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err_or_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 17:57:45 by npineau           #+#    #+#             */
/*   Updated: 2014/06/12 18:12:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		x_int(int err, int res, char *str)
{
	if (res == err)
	{
		fprintf(stderr, "%s error: %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str)
{
	if (res == err)
	{
		fprintf(stderr, "%s error: %s\n", str, strerror(errno));
		exit (1);
	}
	return (res);
}
