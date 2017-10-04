/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:16:35 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 16:22:52 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_get(const char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_GET, arg, cts);
	return (ret);
}
