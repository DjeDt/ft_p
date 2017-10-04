/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:56:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/04 22:00:49 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "readline.h"

/* Pour socket() */
# include <sys/types.h>
# include <sys/socket.h>

/* pour getprotobyname() */
# include <netdb.h>
# include <netinet/in.h>

/* pour htons() */
# include <arpa/inet.h>

/* Pour open() */
# include <fcntl.h>

/* pour les variables en 64b */
# include <stdint.h>

/* builtin sig */
# define SIG_CD 1
# define SIG_LS 2
# define SIG_GET 3
# define SIG_PUT 4
# define SIG_PWD 5
# define SIG_QUIT 6

/* more builtin */
# define SIG_CONNECT 7

/* define signal for communication between client and server */
# define OK			200
# define READY		220
# define GREETING	230
# define NEED_PASS	331
# define ERROR		425 /* can't open data connection */

#endif
