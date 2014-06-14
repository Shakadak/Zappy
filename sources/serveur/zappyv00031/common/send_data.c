/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdefrait <gdefrait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 06:52:50 by gdefrait          #+#    #+#             */
/*   Updated: 2014/05/18 06:52:53 by gdefrait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftp.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

void						send_file(int sock)
{
	char					*filename;

	filename = get_data_from_socket(sock);
	send_file_to_socket(sock, filename);
	free(filename);
	filename = NULL;
	return ;
}

void						send_file_to_socket(int sock, char *filename)
{
	int						fd;
	char					c;
	char					*file;
	struct stat				buf;
	int						i;

	fd = open(filename, O_RDWR);
	i = -1;
	fstat(fd, &buf);
	write(sock, ft_itoa(buf.st_size), 10);
	file = (char *)mmap(0, buf.st_size,
		(PROT_READ | PROT_WRITE | PROT_EXEC), MAP_PRIVATE, fd, 0);
	while (++i < buf.st_size)
	{
		c = file[i];
		write(sock, &c, 1);
	}
	close(fd);
	return ;
}

void						send_data_to_socket(int sock, char *data, int len)
{
	char					c;
	int						i;

	c = 0;
	i = -1;
	write(sock, ft_itoa(len), 10);
	while (++i < len)
	{
		c = data[i];
		write(sock, &c, 1);
	}
	return ;
}
