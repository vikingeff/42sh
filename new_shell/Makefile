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

NAME = minishell3

SRC = 	main.c\
		error.c\
		shell_ini.c\
		sh_exit.c\
		sh_env.c\
		sh_unsetenv.c\
		sh_setenv.c\
		sh_cd.c\
		env_array_to_list.c\
		env_list_to_array.c\
		env_list_add.c\
		env_get_value.c\
		str_join_chr.c\
		prompt_display.c\
		get_next_line.c\
		command_get.c\
		command_parse.c\
		command_get_env.c\
		array2d_free.c\
		command_execute.c\
		command_shell.c\
		ft_strsplit_all.c\
		ft_tablen.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc $(FLAG) $(OBJ) $(LIBFT) -o $(NAME) -g
	@echo "compilation done."

$(LIBFT):
	@make -C libft

%.o: src/%.c
	@cc -c $(FLAGS) $< -I include/ -g

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



