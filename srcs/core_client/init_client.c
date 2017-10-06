/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:04:43 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/19 20:01:20 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	error_proto(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

static int	get_socket(struct protoent *proto)
{
	int	val;
	int sock;

	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (sock == -1)
	{
		val = 1;
		error_proto("error when creating endpoint for communication, trying harder");
		/* force a reutiliser l'addresse si socket a pas reussie */
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
		if (sock == -1)
			return (error_proto("error when creating second endpoint for communication, abort"));
	}
	return (sock);
}

int			init_client(char **argv, t_cts *client_pi, t_cts *client_dtp)
{
	if ((client_pi->proto = getprotobyname("tcp")) == NULL)
		return (error_proto("error when searching for protocol. fatal error"));
	client_pi->sock = get_socket(client_pi->proto);
	client_pi->sin.sin_family = AF_INET;
	client_pi->sin.sin_port = htons(client_pi->port);
	if (!(client_pi->sin.sin_addr.s_addr = inet_addr(argv[1])))
		return (error_proto("address not recognized: abort."));
	client_dtp->port = client_pi->port + 1;
	client_dtp->proto = getprotobyname("tcp");
	client_dtp->sock = get_socket(client_dtp->proto);
	return (0);
}
