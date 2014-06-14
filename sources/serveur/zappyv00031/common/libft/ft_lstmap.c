/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:42:43 by gdefrait          #+#    #+#             */
/*   Updated: 2013/11/21 14:43:13 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;

	if (!lst)
		return (NULL);
	dest = malloc(sizeof(t_list) * lst->content_size);
	while (lst->next)
	{
		dest->content = f(lst->content);
		dest->content = dest->next;
		lst->content = lst->next;
	}
	return (dest);
}
