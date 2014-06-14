/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 04:57:09 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/25 04:57:11 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bircd.h"

int		x_int(int err, int res, char *str)
{
	(void)err;
	(void)res;
	(void)str;
	if (res == err)
	{
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str)
{
	(void)err;
	(void)res;
	(void)str;
	if (res == err)
	{
		exit (1);
	}
	return (res);
}
