/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:50:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 16:30:10 by ddinaut          ###   ########.fr       */
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

static void	print_received_data(int oct, char *data)
{
	ft_putstr("received ");
	ft_putnbr(oct);
	ft_putstr(" octet -> ");
	ft_putendl(data);
}

int		read_from_socket(t_connect *connect)
{
	int ret;
	char buf[1024];

	ret = read(connect->cs, buf, 1023);
	if (ret < 0)
	{
		ft_putendl_fd("read_error: abort prog", 2);
		return (-1);
	}
	buf[ret] = '\0';
	print_received_data(ret, buf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_connect			connect;

	if (argc < 2)
		return (arg_error(argv[0]));
	init_connection(&connect, argv);

	read_from_socket(&connect);
	close(connect.cs);
	close(connect.socket);

	return (0);
}
