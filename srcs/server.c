/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:50:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 22:00:55 by ddinaut          ###   ########.fr       */
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

int			check_builtin(const char *str, t_rfc *connect)
{
	if (!str)
		return (-1);
	if (ft_strcmp(str, "connection") == 0)
	{
		if (received_from_client(connect) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int			core_server(t_rfc *connect)
{
	int		ret;
	pid_t	father;
	char	buf[1024];

	while (1)
	{
		if (waiting_for_client(connect) == -1)
			return (-1);
		if ((father = fork()) == 0)
		{
			while (1)
			{
				ret = read(connect->cli_sock, buf, 1023);
				buf[ret] = '\0';
				if (check_builtin(buf, connect) == 0)
				{
					buf[ret] = '\0';
					ft_putstr("Recu [");
					ft_putnbr(ret);
					ft_putstr("] bytes\n ->");
					ft_putendl(buf);
					if (ft_strcmp(buf, "exit") == 0)
						break ;
				}
			}
		}
		close(connect->cli_sock);
	}
}

int			main(int argc, char **argv)
{
	t_rfc	connect;

	if (argc < 2)
		return (arg_error(argv[0]));
	if ((init_connection(&connect, argv)) == -1)
		return (-1);

	core_server(&connect);

	close(connect.socket);
	return (0);
}
