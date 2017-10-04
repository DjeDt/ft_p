/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:28:00 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 18:20:48 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "main.h"

/* signal to server*/
# define SEND_CD 1
# define SEND_LS 2

typedef struct	s_cts
{
	int					port;
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
}				t_cts;

typedef struct		s_builtin
{
	const char		*ft;
	int				(*func)(const char *cmd, t_cts *cts);
}					t_builtin;

typedef struct	s_signal
{
	const char	*ft;
	int			(*func)(char *buf, int socket);
}				t_signal;

int		init_client(char **argv, t_cts *cts);
int		create_client(t_cts *cts);
int		send_user_information(int socket);

int		handle_input(const char *cmd, t_cts *cts);

int		send_command_to_server(int s, const char *arg, t_cts *cts);
int		ft_cd(const char *arg, t_cts *cts);
int		ft_ls(const char *arg, t_cts *cts);

#endif
