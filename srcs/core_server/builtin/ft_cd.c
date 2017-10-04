/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:45:38 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:03:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		move_dir(const char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0)
		{
			if (chdir(path) == -1)
			{
				ft_putstr_fd("cd: is not a directory: ", 2);
				ft_putendl_fd(path, 2);
				return (-1);
			}
		}
		else
		{
			ft_putstr_fd("cd: permission denied: ", 2);
			ft_putendl_fd(path, 2);
			return (-1);
		}
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
		return (-1);
	}
	return (0);
}

int		ft_cd(char **argv, t_rfc *rfc)
{
	int ret;

	(void)rfc;
	ret = 0;
	if (!argv)
		return (-1);
	if (ft_arrlen(argv) > 2)
	{
		ft_putendl_fd("need only one arg", 2);
		return (-1);
	}
	ret = move_dir(argv[1]);
	return (ret);
}
