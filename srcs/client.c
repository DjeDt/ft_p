/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:39:11 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 17:18:02 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	arg_error(const char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <address> <port> <message>", 2);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_cts	cts;

	if (argc < 4)
		return (arg_error(argv[0]));
	cts.port = ft_atoi(argv[2]);
	argv++;
	init_client(argv, &cts);
	create_client(argv, &cts);

	/* a tester, erreur de argv++ */
	write_to_server(cts.sock, argv);
	close(cts.sock);
	return (0);
}
