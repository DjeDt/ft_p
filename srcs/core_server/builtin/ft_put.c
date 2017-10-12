/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:17:19 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/12 20:25:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	create_file(const char *file)
{
	int fd;
	char	*path;

	path = ft_strjoin("/tmp/", file);

	ft_putstr("file created = ");
	ft_putendl(path);
	fd = open(path, O_TRUNC | O_RDWR | O_CREAT, 0660);
	if (fd == -1)
		ft_putendl("error when creating file");
	return (fd);
}

int			write_in_file(int fd, t_rfc *server)
{
	int test;
	int ret;
	
	while (1)
	{
		if ((ret = recv(server->cli_sock, &test, sizeof(test), 0)) < 0)
		{
			ft_putendl_fd("error when received data from client", 2);
			return (-1);
		}
		if (write(fd, &test, sizeof(test)) < 0)
		{
			ft_putendl_fd("error when write data in specified file", 2);
			return (-1);
		}
		else
			ft_putendl("write in file");
		if (ret == -1)
		{
			ft_putendl("break");
			break ;
		}
	}
	return (0);
}

int			ft_put(char **cmd, t_rfc *server)
{
	int			fd;
	int			ret;
	int			count;

	count = ft_arrlen(cmd);
	if (count == 3)
		fd = create_file(cmd[2]);
	else
		fd = create_file(cmd[1]);
	ret = write_in_file(fd, server);
	return (ret);
}
