#include "server.h"

int		do_builtin(int sig, char *arg, t_rfc *connect)
{
	if (signal == SIG_CD)
		ft_putendl("cd signal received");
	else if (signal == SIG_LS)
		ft_putendl("ls signal received");
	else if (signal == SIG_CONNECT)
		ft_putendl("connection signal received");
	return (0);
}

int		handle_client_demand(int signal, t_rfc *connect)
{
	int		ret;
	char	arg[1024];

	ret = 1;
	ret = recv(connect->cli_sock, arg, 1023, 0);
	arg[ret] = '\0';
	ft_putstr("arg is ");
	ft_putendl(arg);
	ret = do_builtin(sig, arg, connect);
	return (ret);
}
