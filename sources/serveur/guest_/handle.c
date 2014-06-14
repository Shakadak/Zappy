/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 07:40:27 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/18 07:40:29 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftp.h"
#include <unistd.h>

int						ft_handle_who(char *none, int socket_desc)
{
	char				c;

	(void)none;
	c = WHO;
	write(socket_desc, &c, 1);
	return (1);
}

int						ft_handle_msg(char *nickmsg, int socket_desc)
{
	char				c;
	char				*nickname;

	nickname = getuntil(' ', nickmsg);
	c = MSG;
	write(socket_desc, &c, 1);
	send_data_to_socket(socket_desc, nickname, ft_strlen(nickname));
	send_data_to_socket(socket_desc, &nickmsg[ft_strlen(nickname) + 1],
	ft_strlen(&nickmsg[ft_strlen(nickname) + 1]));
	free(nickname);
	nickname = NULL;
	return (1);
}

int						ft_handle_join(char *chan, int socket_desc)
{
	char				c;

	c = JOIN;
	write(socket_desc, &c, 1);
	send_data_to_socket(socket_desc, chan, ft_strlen(chan));
	return (1);
}

int						ft_handle_nick(char *nickname, int socket_desc)
{
	char				c;

	c = NICK;
	write(socket_desc, &c, 1);
	send_data_to_socket(socket_desc, nickname, ft_strlen(nickname));
	return (1);
}

int						ft_handle_all(char *message, int socket_desc)
{
	char				c;

	c = ALL;
	write(socket_desc, &c, 1);
	send_data_to_socket(socket_desc, message, ft_strlen(message));
	return (1);
}
