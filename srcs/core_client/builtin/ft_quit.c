/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:24:38 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 17:15:43 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_quit(const char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_QUIT, arg, cts);
	return (ret);
}
