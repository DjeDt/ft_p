/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:18:34 by ddinaut           #+#    #+#             */
/*   Updated: 2018/01/25 10:12:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_ls(const char *arg, t_cts *cts)
{
	int		ret;
	char	tmp[2];

	(void)arg;
	while (1)
	{
		if ((ret = recv(cts->sock, tmp, 1, 0)) == -1)
		{
			ft_putendl_fd("error when received answer from server" , 2);
			return (-1);
		}
		tmp[ret] = '\0';
		ft_putstr_fd(tmp, 1);
		if (*tmp == '\0')
			break ;
	}
	return (ret);
}
