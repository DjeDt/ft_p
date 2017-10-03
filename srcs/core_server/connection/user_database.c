/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_database.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:08:21 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 18:31:29 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			free_usr_dtb(t_user **root)
{
	t_user *tmp;

	tmp = (*root);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
}

t_user			*create_usr_dtb(const char *usr, const char *mdp)
{
	t_user *new;

	if (!(new = (t_user*)malloc(sizeof(t_user))))
		return (NULL);
	ft_strcpy(new->username, usr);
	ft_strcpy(new->userpass, mdp);
	new->next = NULL;
	return (new);
}

void			add_usr_dtb(t_user **root, const char *usr, const char *mdp)
{
	t_user *tmp;

	if ((*root) == NULL)
		(*root) = create_usr_dtb(usr, mdp);
	else
	{
		tmp = (*root);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_usr_dtb(usr, mdp);
	}
}
