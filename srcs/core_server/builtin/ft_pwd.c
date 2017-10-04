/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:19:35 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:04:03 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_pwd(char **cmd, t_rfc *rfc)
{
	int ret;

	(void)rfc;
	ret = 0;
	if (!cmd)
		return (-1);
	ft_putendl("fonction pwd");
	return (ret);
}
