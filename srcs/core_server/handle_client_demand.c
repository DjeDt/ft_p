/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client_demand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:04:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		modif_fd(int i)
{
	static int save;

	if (i == 0)
	{
	dup2(save, STDIN_FILENO);
	dup2(save, STDOUT_FILENO);
	}
	return (0);
}

int		exec_command(int sig, char **arg, t_rfc *server_pi, t_rfc *server_dtp)
{
	int ret;

	if (sig == SIG_CD)
		ret = ft_cd(arg, server_pi);
	else if (sig == SIG_LS)
		ret = ft_ls(arg, server_pi);
	else if (sig == SIG_GET)
		ret =  ft_get(arg, server_pi);
	else if (sig == SIG_PUT)
		ret = ft_put(arg, server_pi);
	else if (sig == SIG_PWD)
		ret = ft_pwd(arg, server_pi);
	else if (sig == SIG_CONNECT)
		ft_putendl("connection signal received");
	(void)server_dtp;
	return (ret);
}

int		bind_fd_and_exec(int sig, char *arg, t_rfc *server_pi, t_rfc *server_dtp)
{
	int		ret;
	char	**command;

	/* exec builtin */
	if (!(command = ft_strsplit(arg, ' ')))
		return (-1);
	ret = exec_command(sig, command, server_pi, server_dtp);
	if (ret == -1)
		return (-1);
	return (1);
}

int		handle_client_demand(int signal, t_rfc *server_pi, t_rfc *server_dtp)
{
	int		ret;
	char	arg[1024];

	ret = 1;
	ret = recv(server_pi->cli_sock, arg, 1023, 0);
	arg[ret] = '\0';
	ft_putstr("arg is ");
	ft_putendl(arg);
	ret = bind_fd_and_exec(signal, arg, server_pi, server_dtp);
	return (ret);
}
