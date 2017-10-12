#include "server.h"

char	*read_from_socket(t_rfc *server)
{
	int		ret;
	char	tmp[2];
	char	*arg;

	arg = NULL;
	while (1)
	{
		if ((ret = recv(server->cli_sock, tmp, 1, 0)) == -1)
		{
			ft_putendl_fd("read error, try again", 2);
			return (NULL);
		}
		tmp[ret] = '\0';
		if (tmp[0] == '\0')
			return (NULL);
		arg = ft_strjoin_fl(arg, tmp);
		if (tmp[0] == '\n')
			break ;
	}
	return (arg);
}
