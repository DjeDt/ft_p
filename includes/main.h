/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:56:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/10/09 19:23:02 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "readline.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <stdint.h>

/* builtin sig */
# define CMD		0
# define SIG_CD		1
# define SIG_LS		2
# define SIG_GET	3
# define SIG_PUT	4
# define SIG_PWD	5
# define SIG_CNT	6
# define SIG_QUIT	7

/* more builtin */

/* define signal for communication between client and server */
# define OK			200
# define READY		220
# define GREETING	230
# define NEED_PASS	331
# define ERROR		425 /* can't open data connection */

#endif
