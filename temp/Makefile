#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 14:29:03 by cobrecht          #+#    #+#              #
#    Updated: 2014/02/03 14:43:19 by cobrecht         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

SRC = 	main.c\
		error.c\
		command_get.c\
		term_ini.c\
		term_canonical_mode.c\
		term_put.c\
		term_set_attr.c\
		term_close.c\
		key_ESC.c\
		key_ENTER.c\
		key_LEFT.c\
		key_RIGHT.c\
		key_BCKSPC.c\
		key_DEL.c\
		key_JUMP.c\
		edit_char_add.c\
		edit_char_del.c\
		edit_erase_display.c\
		edit_line_display.c\

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc $(FLAG) $(OBJ) $(LIBFT) -L /usr/lib -ltermcap -o $(NAME) -g
	@echo "compilation done."

$(LIBFT):
	@make -C libft

%.o: %.c
	@cc -c $(FLAGS) $< -I. -g

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
	@make -C libft re

git:
	git add src include/shell.h Makefile
	git commit -m "auto push"
	git push

.PHONY: all clean fclean re



