/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:28:00 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 00:47:57 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include "readline.h"

/* Pour socket() */
# include <sys/types.h>
# include <sys/socket.h>

/* pour getprotobyname() */
# include <netdb.h>
# include <netinet/in.h>

/* pour htons */
# include <arpa/inet.h>

/* define signal for communication between client and server */
# define READY "220"
# define NEED_PASS "331"
# define GREETING "230"

typedef struct	s_cts
{
	int					port;
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
}				t_cts;

typedef struct	s_signal
{
	const char	*ft;
	int			(*func)(char **buf, int socket);
}				t_signal;

int		init_client(char **argv, t_cts *cts);
int		create_client(t_cts *cts);
int		send_user_information(int socket);
//int		write_to_server(int socket);

#endif
