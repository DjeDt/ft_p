/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:17:19 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:05:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	create_file(const char *file)
{
	int fd;

	fd = open(file, O_TRUNC | O_WRONLY | O_CREAT);
	if (fd == -1)
		ft_putendl("error when creating file");
	return (fd);
}

int			ft_put(char **cmd, t_rfc *server)
{
	int fd;
	int	count;
	uint64_t test;
	int ret;

	count = ft_arrlen(cmd);
	if (count == 3)
		fd = create_file(cmd[2]);
	else
		fd = create_file(cmd[1]);
	while (1)
	{
		ret = recv(server->cli_sock, &test, sizeof(test), 0);
		if (ret == -1)
		{
			ft_putendl_fd("error when received data from client", 2);
			return (-1);
		}
		if (write(fd, &test, sizeof(test)) < 0)
		{
			ft_putendl_fd("error when write data in specified file", 2);
			return (-1);
		}
		if (ret == 0)
			break ;
	}
	return (ret);
}
