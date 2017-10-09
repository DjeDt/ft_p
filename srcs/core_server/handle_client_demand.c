/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client_demand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 19:48:11 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_connect(char **arg, t_rfc *server_pi)
{
	(void)arg;
	(void)server_pi;
	return (1);
}

void    init_builtin(t_builtin *built)
{
	built[0].ft = "cd";
	built[0].func = &ft_cd;
	built[1].ft = "ls";
	built[1].func = &ft_ls;
	built[2].ft = "get";
	built[2].func = &ft_get;
	built[3].ft = "put";
	built[3].func = &ft_put;
	built[4].ft = "pwd";
	built[4].func = &ft_pwd;
	built[5].ft = "quit";
	built[5].func = &ft_quit;
	built[6].ft = "connect";
	built[6].func = &ft_connect;
}

int		exec_command(const char *arg, int (*func)(char **arg, t_rfc *test),\
					 t_rfc *server_pi, t_rfc *server_dtp)
{
	int		ret;
	char	**command;

	command = ft_strsplit(arg, ' ');
	if (!command)
		return (0);
	
	dup2(server_pi->cli_sock, 0);
	dup2(server_pi->cli_sock, 1);
	dup2(server_pi->cli_sock, 2);
	
	ret = func(command, server_pi);
	ft_arrfree(&command);
	(void)server_dtp;
	return (ret);
}

int		bind_fd_and_exec(const char *arg, t_rfc *server_pi, t_rfc *server_dtp)
{
	int			ret;
	int			count;
	char		*command;
	t_builtin	builtin[7];

	count = -1;
	init_builtin(builtin);
	command = ft_strndup(arg, ft_strnlen(arg, ' '));
	if (command == NULL)
		return (0);
	while (++count < 7)
	{
		if (ft_strcmp(command, builtin[count].ft) == 0)
		{
			ret = exec_command(arg, builtin[count].func, server_pi, server_dtp);
			break ;
		}
	}
	ft_strdel(&command);
	return (1);
}

int		handle_client_demand(t_rfc *server_pi, t_rfc *server_dtp)
{
	int		ret;
	int		sig;
	char	arg[1024];

	sig = READY;
	if ((ret = send(server_pi->cli_sock, &sig, sizeof(sig), 0)) < 0)
	{
		ft_putendl_fd("error when sending signal to client", 2);
		return (1);
	}
	if ((ret = recv(server_pi->cli_sock, arg, 1023, 0)) < 0)
	{
		ft_putendl_fd("error when received command from client", 2);
		return (1);
	}
	arg[ret] = '\0';
	ft_putstr("command received : ");
	ft_putendl(arg);

	ret = bind_fd_and_exec(arg, server_pi, server_dtp);
	return (1);
}
