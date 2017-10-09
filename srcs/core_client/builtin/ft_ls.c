/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:18:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 16:18:37 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_ls(const char *arg, t_cts *cts)
{
	int ret;
	char	tmp[1024];

	ret = send_command_to_server(SIG_LS, arg, cts);
	if (ret == -1)
		return (-1);
	while ((ret = recv(cts->sock, tmp, 1023, 0)) > 0)
	{
		tmp[ret] = '\0';
		ft_putstr_fd(tmp, 1);
	}
	return (ret);
}
