/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:18:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 19:40:47 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_ls(const char *arg, t_cts *cts)
{
	int		ret;
	char	tmp[1024];

	(void)arg;
	while (1)
	{
		if (!(ret = recv(cts->sock, tmp, 1023, 0)))
			return (-1);
		tmp[ret] = '\0';
		ft_putstr(tmp);
		if (ret == 1 && tmp[0] == '\0')
			break ;
	}
	return (ret);
}
