/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:05 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 19:28:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	built_not_found(const char *cmd)
{
	ft_putendl_col_fd("error: ", 2, RED_COL);
	ft_putendl_col_fd(cmd, 2, RED_COL);
	ft_putendl_col_fd(": unknow command", 2, RED_COL);
}

int		ft_connect(const char *str, t_cts *connect)
{
	ft_putendl("module connection ok");
	(void)str;
	(void)connect;
	return (0);
}

void	init_builtin(t_builtin *built)
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

int		send_command_to_server(int s, const char *arg, t_cts *cts)
{
	int	ret;
	int sig;

	sig = s;
	/* sending signal func */
	if ((ret = send(cts->sock, &sig, sizeof(sig), 0)) < 0)
	{
		ft_putendl_col_fd("error when sending signal to server", 2, RED_COL);
		return (-1);
	}
	/* sending full command to server */
	if ((ret = send(cts->sock, arg, ft_strlen(arg), 0)) < 0)
	{
		ft_putendl_col_fd("error when sending signal to server", 2, RED_COL);
		return (-1);
	}
	return (0);
}

int		handle_input(const char *cmd, t_cts *cts)
{
	int			ret;
	int			count;
	char		*command;
	t_builtin	builtin[7];

	ret = -1;
	count = -1;
	init_builtin(builtin);
	command = ft_strndup(cmd, ft_strnlen(cmd, ' '));
	while (++count < 7 && command)
	{
		if (ft_strcmp(command, builtin[count].ft)== 0)
		{
			ret = (builtin[count].func)(cmd, cts);
			break ;
		}
	}
	if (ret == -1)
		built_not_found(command);
	ft_strdel(&command);
	return (1);
}
