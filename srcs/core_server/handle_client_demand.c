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

int		exec_command(int sig, char **arg, t_rfc *rfc)
{
	int ret;

	ret = 0;
	if (sig == SIG_CD)
		ret = ft_cd(arg, rfc);
	else if (sig == SIG_LS)
		ret = ft_ls(arg, rfc);
	else if (sig == SIG_GET)
		ret =  ft_get(arg, rfc);
	else if (sig == SIG_PUT)
		ret = ft_put(arg, rfc);
	else if (sig == SIG_PWD)
		ret = ft_pwd(arg, rfc);
	else if (sig == SIG_CONNECT)
		ft_putendl("connection signal received");
	return (ret);
}

int		bind_fd_and_exec(int sig, char *arg, t_rfc *connect)
{
	int		ret;
	char	**command;

	/* link output from builtin server to client */
//	dup2(connect->socket, STDIN_FILENO);
//	dup2(connect->socket, STDOUT_FILENO);
//	dup2(connect->socket, STDERR_FILENO);

//	close(0);
//	dup2(connect->cli_sock, 0);

	/* exec builtin */
	if (!(command = ft_strsplit(arg, ' ')))
		return (-1);
	ret = exec_command(sig, command, connect);
	return (1);
}

int		handle_client_demand(int signal, t_rfc *connect)
{
	int		ret;
	char	arg[1024];

	ret = 1;
	ret = recv(connect->cli_sock, arg, 1023, 0);
	arg[ret] = '\0';
	ft_putstr("arg is ");
	ft_putendl(arg);
	ret = bind_fd_and_exec(signal, arg, connect);
	return (ret);
}
