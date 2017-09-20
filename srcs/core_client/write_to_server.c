/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:47:31 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 19:40:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		login_phase(int socket)
{
	int		ret;
	char	*buf;
	int		signal;

	ft_putstr("enter username : "); /* begin username phase */
	get_next_line(0, &buf);
	send(socket, buf, ft_strlen(buf), 0); /* sending it to the server  */
	ft_strdel(&buf);

	ret = read(socket, &signal, sizeof(int));

	if (signal == NEED_PASS)
	{
		ft_putstr("enter password : "); /* Asking for password from user */
		get_next_line(0, &buf);
		send(socket, buf, ft_strlen(buf), 0); /* sending it to the server  */
		ft_strdel(&buf);
		ret = read(socket, &signal, sizeof(int));
		if (signal == GREETING)
			return (1);
		else if (signal == ERROR)
			return (-1);
	}
	return (0);
}

int		send_user_information(int socket)
{
	int		ret;
	int		signal;
	char	*buf;

	buf = NULL;
	ret = read(socket, &signal, sizeof(int));
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
