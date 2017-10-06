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

int			ft_put(char **cmd, t_rfc *rfc)
{
	int sig;
	int ret;
	int fd;

	sig = READY;
	fd = create_file(cmd[1]);
	(void)fd;
	send(rfc->cli_sock, &sig, sizeof(sig), 0);
	ret = 0;
	return (ret);
}
