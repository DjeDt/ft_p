/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:40:05 by ddinaut           #+#    #+#             */
/*   Updated: 2018/01/25 10:17:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	built_not_found(const char *cmd)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": unknow command", 2);
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

int		send_2(const char *arg, int len, t_cts *cts)
{
	int		ret;
	int		count;
	char	pack[len + 2];

	count = 0;
	ft_strcpy(pack, arg);
	ft_strcat(pack, "\r\n");
	while (pack[count])
	{
		if ((ret = send(cts->sock, &pack[count], 1, 0)) < 0)
		{
			ft_putendl_fd("error when sending data to server", 2);
			return (-1);
		}
		count++;
	}
	ft_putendl("command sent");
	return (0);
}

int		send_command_to_server(const char *arg, t_cts *cts)
{
	int			ret;
	int			count;
	char		*command;
	t_builtin	builtin[7];

	ret = 0;
	count = -1;
	init_builtin(builtin);
	command = ft_strndup(arg, ft_strnlen(arg, ' '));
	if (!command)
		return (-1);
	while (++count < 7)
	{
		if (ft_strcmp(command, builtin[count].ft) == 0)
		{
			if ((ret = send_2(arg, ft_strlen(arg), cts)) < 0)
				return (-1);
			ret = (builtin[count].func)(arg, cts);
			break ;
		}
	}
	ft_strdel(&command);
	if (count == 7)
	{
		built_not_found(command);
		return (0);
	}
	return (ret);
}

int		handle_input(const char *cmd, t_cts *cts)
{
	int	ret;
	int	sig;

	sig = CMD;
	if ((ret = send(cts->sock, &sig, sizeof(sig), 0)) < 0)
	{
		ft_putendl_col_fd("error when sending signal to server", 2, RED_COL);
		return (1);
	}
	if ((ret = recv(cts->sock, &sig, sizeof(int), 0)) < 0)
	{
		ft_putendl_col_fd("error when waiting for ready signal from server", 2, RED_COL);
		return (1);
	}
	if (sig == READY)
		ret = send_command_to_server(cmd, cts);
	return (ret);
}
