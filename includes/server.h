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

int		create_server(int port);

#endif
