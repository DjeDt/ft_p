/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client_demand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/12 19:56:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_connect(char **arg, t_rfc *server)
{
	(void)arg;
	(void)server;
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
					 t_rfc *server)
{
	int		ret;
	char	**command;

	command = ft_strsplit(arg, ' ');
	if (!command)
		return (0);
	ft_putendl("exec command");
	ret = func(command, server);
	ft_putendl("command executed");
	ft_arrfree(&command);

	return (ret);
}

void	replace(char *src)
{
	int count;

	count = 0;
	while (src[count])
	{
		if (src[count] == '\r' || src[count] == '\n')
			src[count] = '\0';
		++count;
	}
}

int		bind_fd_and_exec(char *arg, t_rfc *server)
{
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
			exec_command(arg, builtin[count].func, server);
			break ;
		}
	}
	ft_strdel(&command);
	return (1);
}

int		handle_client_demand(t_rfc *server)
{
	int		ret;
	int		sig;
	char	*arg;

	sig = READY;
	if ((ret = send(server->cli_sock, &sig, sizeof(sig), 0)) < 0)
	{
		ft_putendl_fd("error when sending signal to client", 2);
		return (1);
	}
	if (!(arg = read_from_socket(server)))
	{
		ft_putendl_fd("error when received command from client", 2);
		return (1);
	}
	replace(arg);

	ft_putstr("command received : ");
	ft_putendl(arg);

	ret = bind_fd_and_exec(arg, server);
	return (1);
}
