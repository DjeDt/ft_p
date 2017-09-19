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

int			init_client(char **argv, t_cts *cts)
{
	int val;

	val = 1;
	argv++;
	if ((cts->proto = getprotobyname("tcp")) == NULL)
		return (error_proto("error when searching for protocol. fatal error"));
	if ((cts->sock = socket(AF_INET, SOCK_STREAM, cts->proto->p_proto)) == -1)
	{
		error_proto("error when creating endpoint for communication, trying harder");
		/* force a reutiliser l'addresse si socket a pas reussie */
		setsockopt(cts->sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
		if (cts->sock == -1)
			return (error_proto("error when creating second endpoint for communication, abort"));
	}
	cts->sin.sin_family = AF_INET;
	cts->sin.sin_port = htons(cts->port);
	cts->sin.sin_addr.s_addr = inet_addr(*argv);
	if ((int)cts->sin.sin_addr.s_addr == -1)
		return (error_proto("address not recognized: abort."));
	return (0);
}
