/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:38:26 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 21:22:37 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	error_proto(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

int			socket_connection(struct protoent *proto)
{
	int sock;
	int val;

	val = 1;
	if ((sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		error_proto("error when creating endpoint for communication, trying harder.");
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
		if (sock == -1)
			return (error_proto("error when creating second endpoint for communication, abort"));
	}
	return (sock);
}



int			create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (error_proto("error when searching for protocol, fatal error"));
	sock = socket_connection(proto);
	if (sock == -1)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (error_proto("bind failed : maybe specified port is already in use"));
	if (listen(sock, 42) == -1)
		return (error_proto("error when trying to listen socket"));
	return (sock);
}
