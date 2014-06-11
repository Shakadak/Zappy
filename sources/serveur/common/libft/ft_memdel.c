/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:13:07 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/21 15:13:22 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void			ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void			sstrmemdel(char ***todel)
{
	int			i;

	i = 0;
	i = ft_sstrlen(todel[0]);
	while (i > 0)
	{
		free(todel[0][i]);
		todel[0][i] = NULL;
		i--;
	}
	free(todel[0]);
	todel[0] = NULL;
	return ;
}
