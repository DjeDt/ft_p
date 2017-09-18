/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:47:31 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/18 16:55:34 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	write_to_server(int socket, char **argv)
{
	while (*argv)
	{
		write(socket, *argv, ft_strlen(*argv));
		argv++;
	}
	return ;
}
