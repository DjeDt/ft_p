#include "client.h"

int		ft_cd(char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_CD, arg, cts);
	ft_putendl("cd send");
	ft_putendl("sending arg");
	ret = send_arg_to_server(ARG_CMD, arg, cts);
	ft_putendl("arg sended");
	return (ret);
}
