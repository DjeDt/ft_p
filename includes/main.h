/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:56:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/09/20 18:59:03 by ddinaut          ###   ########.fr       */
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
#include <fcntl.h>

/* define signal for communication between client and server */
# define OK		200
# define READY	220
# define NEED_PASS 331
# define GREETING 230
# define ERROR 425 /* can't open data connection */


#endif
