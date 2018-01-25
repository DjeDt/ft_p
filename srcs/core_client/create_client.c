/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:39:08 by ddinaut           #+#    #+#             */
/*   Updated: 2018/01/25 09:44:52 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		create_client(t_cts *cts)
{
	if ((connect(cts->sock, (const struct sockaddr*)&cts->sin, sizeof(cts->sin))) == -1)
	{
		ft_putendl_col_fd("connection failed, please try again", 2, RED_COL);
		return (-1);
	}
	return (0);
}
