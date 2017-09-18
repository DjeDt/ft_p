#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 11:05:54 by ddinaut           #+#    #+#              #
#    Updated: 2017/09/18 17:05:55 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output #
SERVEUR		= serveur
CLIENT		= client

# compilation #
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
ADDFLAGS	= #-O1 -g3 -fsanitize=address -fno-omit-frame-pointer

# Directories #
OBJ_PATH	= obj
SRC_PATH	= srcs
LIB_PATH	= libft
INC_PATH	= includes/

# Sub_dirs #
DIR_SER		= core_server/
DIR_CLI		= core_client/

# Colors #
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
PURPLE		= \033[1;35m
WHITE		= \033[1;37m
END_COL		= \033[0m
COUNT		= 1

# libraries #
LIBFT		= -L $(LIB_PATH)
LIBS		= $(LIBFT) -lft
INCLUDES	= -I./ -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH)

# Sources #
SRCS_SER 	= server.c \
			$(DIR_SER)create_server.c \
			$(DIR_SER)init_connection.c

OBJ_SER = $(SRC_SER:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC_SER = $(addprefix $(SRC_PATH)/,$(SRCS_SER))

SRCS_CLI	= client.c \
			$(DIR_CLI)init_client.c \
			$(DIR_CLI)create_client.c \
			$(DIR_CLI)write_to_server.c

OBJ_CLI = $(SRC_CLI:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC_CLI = $(addprefix $(SRC_PATH)/,$(SRCS_CLI))

# Exceptions #
.PHONY: all clean fclean re

# Compilation rules #
all: $(SERVEUR) $(CLIENT)

$(SERVEUR): $(OBJ_SER)
	@printf "Creating server\n"
	@make -sC $(LIB_PATH)
	@$(CC) -o $(SERVEUR) $(FLAGS) $(ADDFLAGS) $(OBJ_SER) $(LIBS)
	@printf "Finished\n"

$(OBJ_SER): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(INCLUDES) -c $<
	@printf "$(GREEN)%s -> %s                                \r$(END_COL)" $@ $<

$(CLIENT): $(OBJ_CLI)
	@printf "Creating client\n"
	@make -sC $(LIB_PATH)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ_CLI) $(LIBS)
	@printf "Finished\n"

$(OBJ_CLI): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
	@printf "$(GREEN)%s -> %s                                \r$(END_COL)" $@ $<

clean:
	@make -sC $(LIB_PATH) clean
	@/bin/rm -f $(OBJS_SER)
	@/bin/rm -f $(OBJS_CLI)

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@/bin/rm -f $(SERVEUR) $(CLIENT)

re: fclean all
