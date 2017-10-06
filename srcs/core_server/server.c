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

int			do_something(t_rfc *server_pi, t_rfc *server_dtp)
{
	int		statut;
	int		ret;
	int		sig;

	statut = 1;
	while (statut)
	{
		if ((ret = recv(server_pi->cli_sock, &sig, sizeof(sig), 0)) == -1)
			break ;
		statut = handle_client_demand(sig, server_pi, server_dtp);
	}
	return (statut);
}

int			core_server(t_rfc *server_pi, t_rfc *server_dtp)
{
	pid_t	father;

	while (1)
	{
		if (waiting_for_client(server_pi , server_dtp) == -1)
			return (-1);
		if ((father = fork()) == 0)
		{
			close(server_pi->socket);
			if (do_something(server_pi, server_dtp) == -1)
				return (-1);
			close(server_pi->cli_sock);
		}
		else
			close(server_pi->cli_sock);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_rfc	server_pi;
	t_rfc	server_dtp;

	if (argc != 2)
		return (arg_error(argv[0]));
	if ((init_connection_server(&server_pi, &server_dtp, argv)) == -1)
		return (-1);
	core_server(&server_pi, &server_dtp);
	close(server_pi.cli_sock);
	close(server_dtp.cli_sock);
	return (0);
}
