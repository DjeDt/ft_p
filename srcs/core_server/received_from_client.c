/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   received_from_client.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:16:01 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 19:40:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	error(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

int		send_success_signal(const int socket)
{
	int signal;

	signal = READY;
	if ((send(socket, &signal, sizeof(int), 0)) == -1)
	{
		error("error when sending signal to client");
		return (-1);
	}
	return (0);
}

int		storing_user_data(t_user *user, int cs)
{
	int ret;
	int signal;

	signal = 220;
	/* connection ok, envoi du signal ok et demande du pseudo */
	if (send_success_signal(cs) != 0)
		return (-1);

	/* reception de l'user */
	ret = recv(cs, user->username, 1023, 0);
	user->username[ret] = '\0';

	/* Demande de mdp */
	signal = NEED_PASS;
	send(cs, &signal, sizeof(int), 0);

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

	connect->cs = accept(connect->socket, (struct sockaddr *)&connect->csin, &connect->cslen);
	if (connect->cs == -1)
		return (error("connection error, try again"));
	if (storing_user_data(&user, connect->cs) == -1)
		return (-1);
	ret = check_user_info(user);
	if (ret == 2)
	{
		signal = GREETING;
		ft_putendl_col("connection garanted !", LIGHT_BLUE);
		send(connect->cs, &signal, sizeof(int), 0);
	}
	else
	{
		signal = ERROR;
		send(connect->cs, &signal, sizeof(int), 0);
		close(connect->cs);
		return (-1);
	}
	return (0);
}
