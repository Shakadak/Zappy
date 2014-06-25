/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 18:14:24 by npineau           #+#    #+#             */
/*   Updated: 2014/06/25 15:01:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "libft.h"
#include "gfx_net.h"

int	create_client(char *addr, int port, t_env *gfx)
{
	int					sock;
	struct protoent		*p;
	struct sockaddr_in	sin;

	p = (struct protoent*)x_void(NULL, getprotobyname("tcp"),
			"getprotobyname", gfx);
	if (p == NULL)
		return (-1);
	sock = x_int(-1, socket(PF_INET, SOCK_STREAM, p->p_proto), "socket", gfx);
	if (sock == -1)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if (ft_strequ(addr, "localhost") || ft_strequ(addr, "-l"))
		addr = ft_strdup("127.0.0.1");
	sin.sin_addr.s_addr = inet_addr(addr);
	ft_strdel(&addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (x_int(-1, -1, "connect", gfx));
	return (sock);
}
