#include "server.h"

/**
   pi = protocole interpreter;
 */

static int	error_proto(const char *error)
{
	ft_putendl_col_fd(error, 2, RED_COL);
	return (-1);
}

static int	socket_connection(struct protoent *proto)
{
	int sock;
	int val;

	val = 1;
	if ((sock = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		ft_putendl_col_fd("error when creating endpoint for communication, trying harder.", 2, RED_COL);
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
		if (sock == -1)
			return (error_proto("error when creating second endpoint for communication, abort"));
	}
	return (sock);
}

static int	create_server(const int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (error_proto("error when searching for protocol: fatal error"));
	sock = socket_connection(proto);
	if (sock == -1)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (error_proto("bind failed : maybe specified port is already in use"));
	if (listen(sock, 42) == -1)
		return (error_proto("error when trying to listen socket"));
	return (sock);
}

int			init_connection_server(t_rfc *server_pi, t_rfc *server_dtp, char **argv)
{
	int	port;

	port = ft_atoi(argv[1]);
	server_pi->port = port;
	if ((server_pi->socket = create_server(port)) == -1)
		return (-1);
	server_dtp->port = port + 1;
	if ((server_dtp->socket = create_server(port + 1)) == -1)
		return (-1);
	return (0);
}
