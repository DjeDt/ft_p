/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:39:11 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 00:36:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	arg_error(const char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <address> <port>", 2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_cts	cts;

	if (argc != 3)
		return (arg_error(argv[0]));
	cts.port = ft_atoi(argv[2]);
	if (init_client(argv, &cts) == -1)
		return (-1);
	if (create_client(&cts) == -1)
		return (-1);
	send_user_information(cts.sock);
//	write_to_server(cts.sock);
	close(cts.sock);
	return (0);
}
