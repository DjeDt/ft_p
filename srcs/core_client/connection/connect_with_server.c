/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_with_server.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:41:15 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 21:59:33 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		send_answer_to_server(const int socket, char *buf)
{
	int ret;

	get_next_line(0, &buf);
	ret = send(socket, buf, ft_strlen(buf), 0);
	if (ret == -1)
		ft_putendl_col_fd("error when sending answer to server", 2, RED_COL);
	ft_strdel(&buf);
	return (ret);
}

int		read_server_answer(const int socket, int *signal)
{
	int	ret;

	ret = read(socket, signal, sizeof(*signal));
	if (ret == -1)
		ft_putendl_col_fd("read failed: critical error", 2, RED_COL);
	return (ret);
}

int		login_phase(int socket)
{
	char	*buf;
	int		signal;

	buf = NULL;
	ft_putstr("enter username : ");
	if (send_answer_to_server(socket, buf) == -1)
		return (-1);
	if (read_server_answer(socket, &signal) == -1)
		return (-1);
	if (signal == NEED_PASS)
	{
		ft_putstr("enter password : ");
		if (send_answer_to_server(socket, buf) == -1)
			return (-1);
		if (read_server_answer(socket, &signal) == -1)
			return (-1);
		if (signal == GREETING)
			return (1);
	}
	return (0);
}

int		send_user_information(int socket)
{
	int		signal;

	if (recv(socket, &signal, sizeof(int), 0) == -1)
	{
		ft_putendl_col_fd("error when waiting for ready signal from server", 2, RED_COL);
		return (-1);
	}
	if (signal == READY)
		ft_putendl("ready response received");
	else
	{
		ft_putendl_col_fd("no response from server", 2, RED_COL);
		return (-1);
	}
	if (login_phase(socket) == 1)
	{
		ft_putendl_col("connection granted", GREEN_COL);
		return (1);
	}
	else
	{
		ft_putendl_col_fd("wrong username or password", 2, RED_COL);
		return (-1);
	}
	return (0);
}
