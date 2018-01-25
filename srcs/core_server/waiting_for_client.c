/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   received_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:25:21 by ddinaut           #+#    #+#             */
/*   Updated: 2018/01/25 09:20:40 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		waiting_for_client(t_rfc *server_pi)
{
	server_pi->cli_sock = accept(server_pi->socket, (struct sockaddr*)&server_pi->cli_sock_in, &server_pi->cli_sock_len);
    if (server_pi->cli_sock == -1)
	{
		ft_putendl_col_fd("connection error, try again", 2, RED_COL);
		return (-1);
	}
	else
		ft_putendl_col("connection established with client", YELLOW_COL);
	return (0);
}
