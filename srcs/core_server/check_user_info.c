/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:55:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 18:39:11 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_user	*searching_for_user(t_user **usr_dtb, const char *data)
{
	t_user *tmp;

	tmp = (*usr_dtb);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->username, data) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		compare_data(t_user **usr_dtb, t_user user)
{
	t_user *tmp;

	tmp = searching_for_user(usr_dtb, user.username);
	if (tmp == NULL)
		return (-1);
	if (ft_strcmp(tmp->userpass, user.userpass) == 0)
		return (2);
	else
		return (1);
}

int		before_compare(t_user **usr_dtb, char *user)
{
	char **tmp;

	tmp = ft_strsplit(user, ':');
	if (tmp == NULL)
		return (-1);
	add_usr_dtb(usr_dtb, tmp[0], tmp[1]);
	ft_arrfree(&tmp);
	return (0);
}

int		check_user_info(t_user user)
{
	int		fd;
	int		ret;
	char	*buf;
	t_user	*usr_dtb;

	buf = NULL;
	usr_dtb = NULL;
	if ((fd = open_file(USR_DTB)) == -1)
		return (-1);
	while (get_next_line(fd, &buf) > 0)
	{
		before_compare(&usr_dtb, buf);
		ft_strdel(&buf);
	}
	close(fd);
	ret = compare_data(&usr_dtb, user);
	return (ret);
}
