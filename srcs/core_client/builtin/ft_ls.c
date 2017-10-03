#include "client.h"

int		ft_ls(char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_LS, arg, cts);
	ft_putendl("ft_ls");
	return (ret);
}
