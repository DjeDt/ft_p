/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:20:29 by ddinaut           #+#    #+#             */
/*   Updated: 2018/01/25 10:11:29 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		put_error(int len)
{
	if (len == 1)
	{
		ft_putendl_fd("error: put: missing file !", 2);
		ft_putendl_fd("type [help put] for usage.", 2);
		return (-1);
	}
	else if (len == 4)
	{
		ft_putendl_fd("error: put: too much arguments !", 2);
		ft_putendl_fd("type [help put] for usage.", 2);
		return (-1);
	}
	return (0);
}

int		open_file2(const char *path)
{
	int fd;

	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0)
		{
			fd = open(path, O_RDONLY);
			return (fd);
		}
		else
			ft_putendl_fd("error: permission denied", 2);
	}
	else
		ft_putendl_fd("error: file doesn't exist", 2);
	return (-1);
}

int		send_file_to_server(int fd, t_cts *cts)
{
	int		ret;
	int		ret2;
	int		test;

	ft_putendl("send file to server");
	while (1)
	{
		ret = read(fd, &test, 1);
		if (ret == -1)
		{
			ft_putendl_fd("error when read file", 2);
			return (-1);
		}
		ret2 = send(cts->sock, &test, sizeof(test), 0);
		if (ret2 == -1)
		{
			ft_putendl_fd("error when sending data to server", 2);
			return (-1);
		}
		if (ret == 0)
			break ;
	}
	return (ret);
}

int			ft_put(const char *arg, t_cts *client)
{
	int		fd;
	int		len;
	char	**name;

	name = ft_strsplit(arg, ' ');
	len = ft_arrlen(name);
	if (put_error(len) == -1)
		return (0);
	if (!(fd = open_file2(name[1])))
		return (0);
	send_file_to_server(fd, client);
	return (1);
}
