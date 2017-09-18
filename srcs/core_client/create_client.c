/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:39:08 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 17:18:07 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		create_client(char **argv, t_cts *cts)
{
	if ((connect(cts->sock, (const struct sockaddr *)&cts->sin, sizeof(cts->sin))) == -1)
	{
		ft_putendl_fd("connect failed : maybe specified port is already in use", 2);
		return (-1);
	}
	return (0);
}
