/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:23:08 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 16:23:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_pwd(const char *arg, t_cts *cts)
{
	int ret;

	ret = send_command_to_server(SIG_PWD, arg, cts);
	return (ret);
}
