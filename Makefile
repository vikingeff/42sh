#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/03 14:29:03 by cobrecht          #+#    #+#              #
#    Updated: 2014/03/23 00:32:25 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 42sh

SRC = 	main.c\
		error.c\
		shell_ini.c\
		sh_exit.c\
		sh_env.c\
		sh_unsetenv.c\
		sh_setenv.c\
		sh_cd.c\
		env_array_to_list.c\
		env_tools.c\
		str_join_chr.c\
		prompt_display.c\
		get_next_line.c\
		command_parse.c\
		command_get_env.c\
		command_execute.c\
		command_shell.c\
		ft_strsplit_all.c\
		ft_tablen.c\
		ft_lst.c\
		ft_modify_arg.c\
		ft_parser_direct.c\
		ft_utility.c\
		ft_signal.c\
		ft_free_arg.c\
		ft_open.c\
		ft_pipe.c\
		ft_execute.c\
		ft_close_count_pipe.c\
		sh_echo.c\
		ft_inib.c\
		ft_parser.c\
		sh_env_utility.c\
		local_var.c\
		command_execute_simple.c\
		sh_cd_goto.c\
		ft_execute_backquote.c\
		ft_delete_char.c\
		sh_cmd.c\
		sh_alias.c\
		ft_get_alias.c\
		sh_unalias.c\
		command_get.c\
		term_modes.c\
		term_put.c\
		keys.c\
		key_JUMP.c\
		key_JUMP_LINE.c\
		edit_key.c\
		edit_char_add.c\
		edit_char_del.c\
		edit_erase_display.c\
		edit_line_display.c\
		edit_list_to_str.c\
		hist.c\
		hist_utils.c\
		hist_navigation.c\
		hist_chr.c\
		hist_launch.c\
		completion.c\
		reset_comp.c\
		fill_completion.c\
		utils.c\
		ft_globing.c\
		ft_parser_next.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cc $(FLAG) $(OBJ) $(LIBFT) -L /usr/lib -ltermcap -o $(NAME)
	@echo "compilation done."

$(LIBFT):
	@make -C libft

%.o: src/%.c
	@cc -c $(FLAGS) $< -I include/

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


