/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:46:47 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 00:53:38 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

pid_t		process_id;

void	ft_print_arg(t_list *arg)
{
	t_list	*dir;
	t_list	*list;

	list = arg;
	while (list)
	{
		printf("\ncommande = %s\n", list->mot);
		printf("synthaxe = %s\n", list->valeure);
		dir = list->dir;
		if (dir)
			printf("	redirection : \n");
		while (dir)
		{
			printf("	direction = %s\n", dir->mot);
			printf("	target = %s\n", dir->valeure);
			dir = dir->next;
		}
		list = list->next;
	}
}

int		main(int ac, char **environ)
{
	t_env	env;
	t_dir	dir;
	t_cmd	cmd;
	int		ret;
	t_list	*arg;

	arg = NULL;
	env.raw = environ;
	process_id = -2;
	ft_signal();
	if (ac > 1)
		return (error(0, NULL));
	if (shell_ini(&cmd, &dir, &env))
		return (-1);
	while (!cmd.exit)
	{
		env.prompt = prompt_display(&dir);
		env.prompt_len = ft_strlen(env.prompt);
		term_edit_set(&env);
		if (command_get(&env, &cmd))
		{
			term_std_set(&env);
			if (!cmd.raw)
				continue ;
			if (ft_inib_starter(&cmd))
				continue ;
			ft_get_alias(&cmd);
			if (arg)
				ft_free_arg(arg);
			arg = ft_parser(cmd.raw);
			ft_print_arg(arg);
			if (ft_launcher(arg, &cmd, &env, &dir) == -1)
				return (0);
		}
		else
			cmd.exit = 1;
	}
	term_close(&env);
	delete_temp_free(arg, &cmd, &env, &dir);
	return (0);
}
