/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:50:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/19 23:59:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	arg_error(const char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <port>", 2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_rfc	connect;

	if (argc < 2)
		return (arg_error(argv[0]));
	if ((init_connection(&connect, argv)) == -1)
		return (-1);
	if (received_from_client(&connect) == -1)
		return (-1);
	close(connect.socket);
	return (0);
}
