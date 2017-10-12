/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:51:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/12 19:24:14 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_ls(char **argv, t_rfc *server)
{
	int		statut;
	int		backup;
	pid_t	father;

	statut = 1;
	if (!argv)
		return (-1);
	backup = dup(0);
	backup = dup(1);
	backup = dup(2);
	dup2(server->cli_sock, 0);
	dup2(server->cli_sock, 1);
	dup2(server->cli_sock, 2);

	if ((father = fork()) == 0)
	{
		execv("/bin/ls", argv);
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": not found", 2);
		exit(1);
	}
	else
		wait4(father, &statut, 0, 0);
	ft_putchar('\0');

	dup2(backup, 0);
	dup2(backup, 1);
	dup2(backup, 2);
	return (0);
}
