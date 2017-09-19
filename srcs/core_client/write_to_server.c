/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:47:31 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 00:48:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


/* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */
/*																					   */
/*-> faire un handler pour les signaux du server, comme pour les bulidin du minishell  */
/*																					   */
/* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */ /* */

/*
int		username(char **buf, int socket)
{
	ft_putstr("enter username : ");
	get_next_line(0, buf);
}

int		password()
{

}

void	init_sig_handler(t_signal sh, char **buf)
{
	sh[0].ft =
}

int		analyze_server_demand(int socket)
{
	int			end;
	t_signal	sig_handler[4];

	init_sig_handler(sig_handler);
	end = 0;
	while (1)
	{

	}
}
*/

int		send_user_information(int socket)
{
	int		ret;
	char	test[1024];
	char *buf = NULL;

	ret = read(socket, test, 1023);
	test[ret] = '\0';

	if (ft_strcmp(test, READY) == 0)
		ft_putendl("ready response received");
	else
	{
		ft_putendl_fd("no ready answer received", 2);
		return (-1);
	}

	/* begin username phase */
	ft_putstr("enter username : ");
	get_next_line(0, &buf);

	/* sending it to the server  */
	send(socket, buf, ft_strlen(buf), 0);
	ft_strdel(&buf);

	/* waiting for password demand */
	ret = read(socket, test, 1023);
	test[ret] = '\0';

//	ret = get_next_line(socket, &buf);
	if (ft_strcmp(test, NEED_PASS) == 0)
		ft_putendl("need password");
	else
	{
		ft_putendl_fd("no password demand received", 2);
		return (-1);
	}

	ft_putstr("enter password : ");
	get_next_line(0, &buf);

	/* sending it to the server  */
	send(socket, buf, ft_strlen(buf), 0);
	ft_strdel(&buf);

	ret = read(socket, test, 1023);
	test[ret] = '\0';
	if (ft_strcmp(test, GREETING) == 0)
	{
		ft_putendl("de rien :)");
	}

	return (0);
}
