/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   received_from_client.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:16:01 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 00:49:55 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	error(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

void	print_received_data(int oct, char *data)
{
	ft_putstr_col("received : ", RED_COL);
	ft_putstr(data);
	ft_putstr_col(" octet -> ", GREEN_COL);
	ft_putnbr(oct);
	ft_putchar('\n');
}

int		send_success_signal(const int socket)
{
	if ((send(socket, READY, ft_strlen(READY), 0)) == -1)
	{
		error("error when sending signal to client");
		return (-1);
	}
	return (0);
}

int			received_from_client(t_rfc *connect)
{
	int		ret;
	t_user	user;

	connect->cs = accept(connect->socket, (struct sockaddr *)&connect->csin, &connect->cslen);
	if (connect->cs == -1)
		return (error("connection error, try again"));

	/* sending success signal */
	if (send_success_signal(connect->cs) != 0)
		return (-1);

	/* recuperer le username */

	ret = recv(connect->cs, user.username, 1023, 0);
	if (ret == -1)
	{
		ft_putendl_fd("error with recv", 2);
		return (-1);
	}
	user.username[ret] = '\0';

	ft_putstr("username received is : ");
	ft_putendl_col(user.username, LIGHT_GREEN);

	/* demander le password */
	send(connect->cs, NEED_PASS, ft_strlen(NEED_PASS), 0);

	ret = recv(connect->cs, user.userpass, 1023, 0);
	user.userpass[ret] = '\0';

	ft_putstr("password received is : ");
	ft_putendl_col(user.userpass, LIGHT_GREEN);

	/* send 220 "merci" response */
	send(connect->cs, GREETING, ft_strlen(GREETING), 0);

	ft_putendl_col("connection garanted !", LIGHT_BLUE);
	return (0);



	/*
	int		ret;
	char	buf[1024];
	pid_t	father;

	ret = 0;
	while (1)
	{
	connect->cs = accept(connect->socket, (struct sockaddr *)&connect->csin, &connect->cslen);
		if (connect->cs == -1)
			return (error("connection error, try again"));
		if ((father = fork()) == 0)
		{
			while ((ret = read(connect->cs, buf, 1023)) > 0)
			{
				print_received_data(ret, buf);
				ft_putendl_fd("data received", connect->cs);
				if (ft_strcmp(buf, "qserver") == 0)
				{
					ft_putendl_fd("break from while", 2);
					break ;
				}
			}
			close(connect->cs);
			exit(0);
		}
		close(connect->cs);
	}
	return (0);
	*/
}
