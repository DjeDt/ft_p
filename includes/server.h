/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:27:55 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 00:32:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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

typedef	struct	s_rfc
{
	int					port;
	int					socket;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
}				t_rfc;

typedef struct	s_user
{
	char	username[1024];
	char	userpass[1024];
}				t_user;

int		create_server(int port);
int		init_connection(t_rfc *connect, char **argv);
int		received_from_client(t_rfc *connect);

#endif
