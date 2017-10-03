#include "client.h"

int		port(char **argv, const char *port)
{
	ft_putstr("sending to server port : ");
	ft_putendl(port);
	send();
}
