#ifndef CLIENT_H
# define CLIENT_H

#include "libft.h"

#include "libft.h"

/* Pour socket() */
#include <sys/types.h>
#include <sys/socket.h>

/* pour getprotobyname() */
#include <netdb.h>
#include <netinet/in.h>

/* pour htons */
#include <arpa/inet.h>

int		create_client(const char *address, int port);
#endif
