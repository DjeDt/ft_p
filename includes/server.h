/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:27:55 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 19:01:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "main.h"

# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>


# define PUT_USAGE "usage: put [fichier-local] -> [fichier-distant]\n\
					[fichier-distant] est optionnel."

typedef struct			s_user
{
	char				username[1024];
	char				userpass[1024];
	struct s_user		*next;
}						t_user;

typedef	struct			s_rfc
{
	int					port;
	int					socket;
	int					socket_dtp;
	int					cli_sock;
	int					cli_sock_dtp;
	unsigned int		cli_sock_len;
	struct sockaddr_in	cli_sock_in;
}						t_rfc;

typedef struct			s_builtin
{
	const char			*ft;
	int					(*func)(char **cmd, t_rfc *server);
}						t_builtin;

# ifdef __APPLE__
	# define USR_DTB "/Users/ddinaut/Dev/ft_p/.usr_database"
# elif __linux
	# define USR_DTB "/home/dje/Dev/ft_p/.usr_database"
# endif

int		init_connection_server(t_rfc *server, char **argv);
int		received_from_client(t_rfc *server);
int		waiting_for_client(t_rfc *server);
int		handle_client_demand(t_rfc *server);

char	*read_from_socket(t_rfc *server);

/* Builtins */
int		ft_cd(char **argv, t_rfc *server);
int		ft_ls(char **argv, t_rfc *server);
int		ft_get(char **argv, t_rfc *server);
int		ft_put(char **argv, t_rfc *server);
int		ft_pwd(char **argv, t_rfc *server);
int		ft_quit(char **argv, t_rfc *server);
/* builtin connection */
int		check_user_info(t_user user);
t_user	*create_usr_dtb(const char *user, const char *mdp);
void	add_usr_dtb(t_user **root, const char *usr, const char *mdp);

#endif
