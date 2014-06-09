/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 04:03:17 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/18 04:03:18 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftp.h"
#include <fcntl.h>
#include <unistd.h>

void						get_file(int sock)
{
	char					*filename;

	filename = get_data_from_socket(sock);
	get_file_from_socket(sock, filename);
	free(filename);
	filename = NULL;
	return ;
}

char						*get_data_from_socket(int sock)
{
	int						len;
	char					nbbuf[10];
	char					*file;
	int						i;

	i = -1;
	read(sock, &nbbuf, 10);
	len = ft_atoi(nbbuf);
	file = (char *)malloc(sizeof(char) * (len + 10));
	file[0] = '\0';
	while (++i < len)
	{
		if (read(sock, &file[i], 1) < 0)
		{
			ft_putstr("Sorry bye bye: Connection interrupted :s...");
			exit(0);
		}
	}
	file[len] = '\0';
	return (file);
}

void						get_file_from_socket(int sock, char *filename)
{
	t_count					c;
	char					nbbuf[10];

	read(sock, &nbbuf, 10);
	c.len = ft_atoi(nbbuf);
	c.file = (char *)malloc(sizeof(char) * c.len);
	c.i = -1;
	while (++c.i < c.len)
		read(sock, &c.file[c.i], 1);
	c.file[c.len] = '\0';
	c.fd = open(filename, (O_RDWR | O_CREAT | O_TRUNC | O_NONBLOCK), 0000755);
	c.i = -1;
	while (++c.i < c.len)
	{
		c.c = c.file[c.i];
		write(c.fd, &c.c, 1);
	}
	free(c.file);
	c.file = NULL;
	close(c.fd);
	return ;
}
