/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:04:43 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 17:14:43 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		init_client(char **argv, t_cts *cts)
{
	cts->proto = getprotobyname("tcp");
	if (cts->proto == NULL)
	{
		ft_putendl_fd("getprotobyname failed", 2);
		return (-1);
	}

	cts->sock = socket(AF_INET, SOCK_STREAM, cts->proto->p_proto);
	cts->sin.sin_family = AF_INET;
	cts->sin.sin_port = htons(cts->port);
	cts->sin.sin_addr.s_addr = inet_addr(*argv);
	argv++;

	return (0);
}
