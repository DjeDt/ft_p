#include "server.h"

static int	arg_error(const char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <address> <port> <message>", 2);
	return (-1);
}

static int	create_client(char *address, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == NULL)
		return (-1);
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(address);
	if ((connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putendl_fd("connect failed : maybe specified port is already in use", 2);
		return (-1);
	}
	return (sock);
}

int		main(int argc, char **argv)
{
	int					port;
	int					socket;

	if (argc < 4)
		return (arg_error(argv[0]));
	port = ft_atoi(argv[2]);
	socket = create_client(argv[1], port);
	write(socket, argv[3], ft_strlen(argv[3]));
	close(socket);
	return (0);
}
