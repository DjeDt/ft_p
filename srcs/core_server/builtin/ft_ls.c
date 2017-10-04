/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:51:06 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:03:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_ls(char **argv, t_rfc *rfc)
{
	if (!argv)
		return (-1);
	ft_putendl("ls = ");
	(void)rfc;
	int count;
	count = 0;
	while (argv[count])
		ft_putendl(argv[count++]);
	return (0);
}
