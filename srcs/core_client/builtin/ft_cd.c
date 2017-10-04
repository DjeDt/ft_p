#include "client.h"

int		ft_cd(const char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_CD, arg, cts);
	return (ret);
}
