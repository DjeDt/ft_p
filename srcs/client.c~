#include "server.h"

static int	arg_error(const char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <port>", 2);
	return (-1);
}

static int	create_server(int port)
{
	int						sock;
	struct protoent			*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == NULL)
		return (-1);
	sock = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putendl_fd("bind failed : maybe specified port is already in use", 2);
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int argc, char **argv)
{
	int					port;
	int					socket;
	int					cs;
	int					ret;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	char				buf[1024];

	if (argc < 2)
		return (arg_error(argv[0]));
	port = ft_atoi(argv[1]);
	socket = create_server(port);
	cs = accept(socket, (struct sockaddr *)&csin, &cslen);
	if (cs == -1)
		return (-1);
	while ((ret = read(cs, buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr("received ");
		ft_putnbr(ret);
		ft_putstr(" octet -> ");
		ft_putendl(buf);
	}
	if (ret == 0)
		ft_putendl("connection stopped, see ya !");
	if (ret == -1)
		ft_putendl_fd("unexpected error, try again", 2);
	close(cs);
	close(socket);
	return (0);
}
