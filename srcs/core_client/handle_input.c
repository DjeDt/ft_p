#include "client.h"

void	init_builtin(t_builtin *built)
{
	built[0].ft = "cd";
	built[0].func = &ft_cd;
	built[1].ft = "ls";
	built[1].func = &ft_ls;
}

int		send_command_to_server(int s, const char *arg, t_cts *cts)
{
	int	ret;
	int sig;

	sig = s;
	/* sending command signal, maybe useless */
	ret = send(cts->sock, &sig, sizeof(sig), 0);
	if (ret < 0)
	{
		ft_putendl_col_fd("error when sending signal to server", 2, RED_COL);
		return (-1);
	}
	/* sending full command to server */
	ret = send(cts->sock, arg, ft_strlen(arg), 0);
	return (0);
}

int		handle_input(const char *cmd, t_cts *cts)
{
	int			ret;
	int			count;
	char		*command;
	t_builtin	builtin[3];

	ret = 1;
	count = -1;
	init_builtin(builtin);
	command = ft_strndup(cmd, ft_strnlen(cmd, ' '));
	while (++count < 2 && command)
	{
		if (ft_strcmp(command, builtin[count].ft)== 0)
		{
			ret = (builtin[count].func)(cmd, cts);
			break ;
		}
	}
	ft_strdel(&command);
	return (ret);
}
