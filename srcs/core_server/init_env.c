#include "server.h"

int		init_env(char **env)
{
	if (!(env = (char*)malloc(sizeof(char*) * (1))))
		return (-1);
	env[0] = NULL;

}
