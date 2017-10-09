/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:51:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:03:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_ls(char **argv, t_rfc *server_pi)
{
	pid_t	father;

	if (!argv)
		return (-1);
	father = fork();
	if (father == 0)
	{
		dup2(server_pi->cli_sock, 0);
		dup2(server_pi->cli_sock, 1);
		execv("/bin/ls", argv);
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": not found", 2);
		exit(0);
	}
	wait4(father, 0, 0, 0);
	(void)server_pi;
	return (0);
}
