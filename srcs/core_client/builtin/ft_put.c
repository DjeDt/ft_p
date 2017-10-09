/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:20:29 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 18:16:22 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		put_error(int len)
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
	if (!path)
		put_error(1);
	return (-1);
}

int			ft_put(const char *arg, t_cts *cts)
{

	(void)arg;
	(void)cts;
	return (1);
}
