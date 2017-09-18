/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:28:00 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 17:12:46 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "libft.h"

/* Pour socket() */
#include <sys/types.h>
#include <sys/socket.h>

/* pour getprotobyname() */
#include <netdb.h>
#include <netinet/in.h>

/* pour htons */
#include <arpa/inet.h>

typedef struct	s_cts
{
	int					port;
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
}				t_cts;

int		init_client(char **argv, t_cts *cts);
int		create_client(char **argv, t_cts *cts);
void	write_to_server(int socket, char **argv);

#endif
