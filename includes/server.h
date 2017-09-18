/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:27:55 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 16:30:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include "libft.h"

/* Pour socket() */
#include <sys/types.h>
#include <sys/socket.h>

/* pour getprotobyname() */
#include <netdb.h>
#include <netinet/in.h>

/* pour htons */
#include <arpa/inet.h>

typedef	struct	s_connect
{
	int					port;
	int					socket;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
}				t_connect;

int		init_connection(t_connect *connect, char **argv);
int		create_server(int port);
int		read_from_socket(t_connect *connect);

#endif
