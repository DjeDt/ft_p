/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:37:08 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 16:29:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		init_connection(t_connect *connect, char **argv)
{
	int	ret;

	connect->port = ft_atoi(argv[1]);
	connect->socket = create_server(connect->port);
	ret = 0;
	while (1)
	{
		connect->cs = accept(connect->socket, (struct sockaddr *)&connect->csin, &connect->cslen);
		if (connect->cs == -1)
		{
			ft_putendl("connection error");
			exit (-1);
		}
		ret = read_from_socket(connect);
		if (ret == -1)
			return (-1);
	}
	return (0);
}
