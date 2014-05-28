# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/16 10:47:30 by fgrivill          #+#    #+#              #
#    Updated: 2014/05/28 11:01:45 by cnathana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

FILES = basicenv cd check_token echo error_files error_open\
		ft_valid_cmd get_cmd getenv main parse pipe signals\
		token env setenv exec ft_init_larrow free replace\
		ft_init_rarrow builtin waitchild exec_tokens\
		add_del_char get_cmd_init special_keys tinit\
		print_prompt

SRCS = $(addsuffix .c, $(addprefix srcs/, $(FILES)))

OBJ = $(SRCS:.c=.o)

CC = @gcc
CFLAGS = -Wall -Wextra -Werror -g

TCAP = -L /usr/lib -ltermcap

LIB = -L libft -lft

NONE = \033[0m
COL = \033[35m
RED = \033[1;31m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(TCAP)
	@echo "$(COL)$(NAME)$(NONE) created."

%.o: %.c
	$(CC) $(CFLAGS) -c -I./libft/includes -I./includes $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(NONE) removed."

re: fclean all

.PHONY: all re clean fclean
