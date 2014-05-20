# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/16 10:49:16 by fgrivill          #+#    #+#              #
#    Updated: 2014/05/16 11:04:51 by fgrivill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc 
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/ft_strlen.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_icharjoin.c\
	   srcs/ft_charjoin.c srcs/ft_strcpy.c srcs/ft_strsub.c srcs/ft_putendl.c\
	   srcs/ft_ichardelet.c srcs/ft_strcat.c srcs/ft_bzero.c srcs/tputchar.c\
	   srcs/ft_strncmp.c srcs/ft_strsplit.c srcs/ft_strdup.c srcs/ft_strtrim.c\
	   srcs/ft_isspace.c srcs/ft_get_next_line.c srcs/ft_strnjoin.c\
	   srcs/ft_strjoin.c srcs/ft_putstr_fd.c

OBJ = $(SRCS:.c=.o)

NONE = \033[0m
COL = \033[35m
RED = \033[1;31m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(COL)$(NAME)$(NONE) created."

%.o: %.c
	$(CC) $(CFLAGS) -c -I./includes $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(NONE) removed."

re: fclean all

.PHONY: all re clean fclean
