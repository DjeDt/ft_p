/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   received_from_client.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:16:01 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 21:45:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	error(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

int		send_signal_to_client(const int socket, int *signal)
{
	int ret;

	ret = send(socket, signal, sizeof(*signal), 0);
	if (ret == -1)
		error("error when sending signal to client");
	return (ret);
}

int		storing_user_data(t_user *user, int cs)
{
	int ret;
	int signal;

	/* connection ok, envoi du signal ok et demande du pseudo */
	signal = READY;
	if (send_signal_to_client(cs, &signal) == -1)
		return (-1);

	/* reception de l'user */
	ret = recv(cs, user->username, 1023, 0);
	user->username[ret] = '\0';

	/* Demande de mdp */
	signal = NEED_PASS;
	if (send_signal_to_client(cs, &signal) == -1)
		return (-1);

	/* reception du mdp */
	ret = recv(cs, user->userpass, 1023, 0);
	user->userpass[ret] = '\0';

	/* pas utile ici mais c'est toujours mieux */
	user->next = NULL;
	return (0);
}

int		received_from_client(t_rfc *connect)
{
	int		ret;
	int		signal;
	t_user	user;

	if (storing_user_data(&user, connect->cli_sock) == -1)
		return (-1);
	ret = check_user_info(user);
	if (ret == 2)
	{
		signal = GREETING;
		send_signal_to_client(connect->cli_sock, &signal);
		ft_putendl_col("connection garanted !", LIGHT_BLUE);
	}
	else
	{
		signal = ERROR;
		send_signal_to_client(connect->cli_sock, &signal);
		ft_putendl_col_fd("error when looking for user, abort", 2, RED_COL);
		return (-1);
	}
	return (ret);
}
