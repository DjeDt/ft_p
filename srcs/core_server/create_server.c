/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:38:26 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 16:25:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		create_server(int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == NULL)
	{
		ft_putendl_fd("getprotobyname error", 2);
		return (-1);
	}
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putendl_fd("bind failed : maybe specified port is already in use", 2);
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}
