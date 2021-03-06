#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 11:05:54 by ddinaut           #+#    #+#              #
#    Updated: 2018/01/25 10:07:35 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output #
SERVEUR		= serveur
CLIENT		= client

# compilation #
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
DEBUG		= n
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
			$(DIR_SER)init_server.c \
			$(DIR_SER)waiting_for_client.c \
			$(DIR_SER)handle_client_demand.c \
			$(DIR_SER)read_from_socket.c \
\
			$(DIR_SER)$(BUILTIN)ft_cd.c \
			$(DIR_SER)$(BUILTIN)ft_ls.c \
			$(DIR_SER)$(BUILTIN)ft_get.c \
			$(DIR_SER)$(BUILTIN)ft_put.c \
			$(DIR_SER)$(BUILTIN)ft_pwd.c \
			$(DIR_SER)$(BUILTIN)ft_quit.c \
			$(DIR_SER)$(BUILTIN)$(CONNECTION)received_from_client.c \
			$(DIR_SER)$(BUILTIN)$(CONNECTION)check_user_info.c \
			$(DIR_SER)$(BUILTIN)$(CONNECTION)user_database.c \

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

# Percent Progress
COUNT_S       	= 1
COUNT_C       	= 1
NB_FILES_SER	= $(words $(SRCS_SER))
NB_FILES_CLI	= $(words $(SRCS_CLI))
PERCENT_SER    	= $(shell echo $$(( ($(COUNT_S) * 100) / $(NB_FILES_SER))))
PERCENT_CLI    	= $(shell echo $$(( ($(COUNT_C) * 100) / $(NB_FILES_CLI))))

# Exceptions #
.PHONY: all clean fclean re

# Compilation rules #
all: $(SERVEUR) $(CLIENT)

$(SERVEUR): $(OBJ_SER)
	@make -sC $(LIB_PATH)
	@$(CC) -o $(SERVEUR) $(FLAGS) $(ADDFLAGS) $(OBJ_SER) $(LIBS)
	@printf "$(GREEN)\r\033[KServer is ready to works\n$(END_COL)"

$(OBJ_SER): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(INCLUDES) -c $<
	@printf "\r\033[K$(RED)[%-5.2f%%]  \e[1;38;5;148m[$@] -> [$<]$(END_COL)" $(PERCENT_SER)
	$(eval COUNT_S=$(shell echo $$(($(COUNT_S)+1))))

$(CLIENT): $(OBJ_CLI)
	@make -sC $(LIB_PATH)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ_CLI) $(LIBS)
	@printf "$(GREEN)\r\033[KClient is ready to works\n$(END_COL)"

$(OBJ_CLI): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
	@printf "\r\033[K$(RED)[%-5.2f%%]  \e[1;38;5;148m[$@] -> [$<]$(END_COL)" $(PERCENT_CLI)
	$(eval COUNT_C=$(shell echo $$(($(COUNT_C)+1))))

clean:
	@make -sC $(LIB_PATH) clean
	@/bin/rm -f $(OBJ_SER)
	@/bin/rm -f $(OBJ_CLI)

fclean: clean
	@make -sC $(LIB_PATH) fclean
	@/bin/rm -f $(SERVEUR) $(CLIENT)
	@/bin/rm -rf $(OBJ_PATH)

re: fclean all
