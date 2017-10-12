/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:51:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 19:48:15 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_ls(char **argv, t_rfc *server_pi)
{
	int		statut;
	pid_t	father;

	statut = 1;
	if (!argv)
		return (-1);
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
	(void)server_pi;
	return (0);
}
