/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:37:08 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/19 18:14:57 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		init_connection(t_rfc *connect, char **argv)
{
	connect->port = ft_atoi(argv[1]);
	connect->socket = create_server(connect->port);
	if (connect->socket == -1)
		return (-1);
	return (0);
}
