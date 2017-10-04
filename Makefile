#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 11:05:54 by ddinaut           #+#    #+#              #
#    Updated: 2017/10/04 17:18:53 by ddinaut          ###   ########.fr        #
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
CONNECTION	= connection/
READLINE	= readline/
BUILTIN		= builtin/

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
SRCS_SER 	= \
			$(DIR_SER)server.c \
			$(DIR_SER)create_server.c \
			$(DIR_SER)init_connection.c \
			$(DIR_SER)waiting_for_client.c \
			$(DIR_SER)handle_client_demand.c \
\
			$(DIR_SER)$(BUILTIN)ft_cd.c \
			$(DIR_SER)$(BUILTIN)ft_ls.c \
			$(DIR_SER)$(BUILTIN)ft_get.c \
			$(DIR_SER)$(BUILTIN)ft_put.c \
			$(DIR_SER)$(BUILTIN)ft_pwd.c \
			$(DIR_SER)$(BUILTIN)ft_quit.c \
\
			$(DIR_SER)$(CONNECTION)received_from_client.c \
			$(DIR_SER)$(CONNECTION)check_user_info.c \
			$(DIR_SER)$(CONNECTION)user_database.c \
\
			$(DIR_SER)$(READLINE)add_char.c \
			$(DIR_SER)$(READLINE)change_term_mode.c \
			$(DIR_SER)$(READLINE)cursor_move.c \
			$(DIR_SER)$(READLINE)hist_utils.c \
			$(DIR_SER)$(READLINE)history.c \
			$(DIR_SER)$(READLINE)key_delete.c \
			$(DIR_SER)$(READLINE)match_key.c \
			$(DIR_SER)$(READLINE)read_line.c

OBJ_SER = $(SRC_SER:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC_SER = $(addprefix $(SRC_PATH)/,$(SRCS_SER))

SRCS_CLI	= \
			$(DIR_CLI)client.c \
			$(DIR_CLI)init_client.c \
			$(DIR_CLI)create_client.c \
			$(DIR_CLI)handle_input.c \
\
			$(DIR_CLI)$(BUILTIN)ft_ls.c \
			$(DIR_CLI)$(BUILTIN)ft_cd.c \
			$(DIR_CLI)$(BUILTIN)ft_get.c \
			$(DIR_CLI)$(BUILTIN)ft_put.c \
			$(DIR_CLI)$(BUILTIN)ft_pwd.c \
			$(DIR_CLI)$(BUILTIN)ft_quit.c \
\
			$(DIR_CLI)$(CONNECTION)connect_with_server.c \
\
			$(DIR_CLI)$(READLINE)add_char.c \
			$(DIR_CLI)$(READLINE)change_term_mode.c \
			$(DIR_CLI)$(READLINE)cursor_move.c \
			$(DIR_CLI)$(READLINE)hist_utils.c \
			$(DIR_CLI)$(READLINE)history.c \
			$(DIR_CLI)$(READLINE)key_delete.c \
			$(DIR_CLI)$(READLINE)match_key.c \
			$(DIR_CLI)$(READLINE)read_line.c

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
	@/bin/rm -f $(OBJ_SER)
	@/bin/rm -f $(OBJ_CLI)

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@/bin/rm -f $(SERVEUR) $(CLIENT)
	@/bin/rm -rf $(OBJ_PATH)

re: fclean all
