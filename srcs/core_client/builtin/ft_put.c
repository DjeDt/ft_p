/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:20:29 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:11:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	put_error(int len)
{
	if (len == 1)
	{
		ft_putendl_fd("error: put: missing file !", 2);
		ft_putendl_fd("type [help put] for usage.", 2);
	}
	else if (len == 3)
	{
		ft_putendl_fd("error: put: too much arguments !", 2);
		ft_putendl_fd("type [help put] for usage.", 2);
	}
	return (-1);
}

static int	open_file2(const char *path)
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
	if (!path)
		put_error(1);
	return (-1);
}

void		sending_file_to_server(int fd,const char *arg, t_cts *cts)
{
	int		sig;
	void	*tmp;

	tmp = NULL;
	(void)sig;
	(void)arg;
	while (get_next_line(fd, (char**)&tmp))
	{
		send(cts->sock, tmp, BUFF_SIZE, 0);
		ft_memdel(&tmp);
	}
}

int			ft_put(const char *arg, t_cts *cts)
{
	int		sig;
	int ret;
	int fd;
	char **command;

	command = ft_strsplit(arg, ' ');
	sig = SIG_PUT;
	if (!(ret = send(cts->sock, &sig, sizeof(sig), 0)))
	{
		ft_putendl_fd("error when sending signal to server", 2);
		return (-1);
	}
	fd = open_file2(command[1]);
	recv(cts->sock, &sig, sizeof(sig), 0);
	if (sig == READY)
		sending_file_to_server(fd, arg, cts);
	else
	{
		ft_putendl_fd("error: no response from server", 2);
		return (-1);
	}
	return (ret);
}
