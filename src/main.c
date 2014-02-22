/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:46:47 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 15:25:15 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

pid_t		process_id;

static void	ft_get_signal(int n)
{
	if (n == SIGINT)
	{
		if (kill(process_id, SIGINT) == -1)
		{
			ft_putstr("\n");
			prompt_display(NULL);
		}
	}
}

void		ft_signal(void)
{
	signal(SIGINT, ft_get_signal);
}

t_list	*ft_parser(char *str)
{
	t_list	*arg;
	int		index;
	int		start;

	index = 0;
	start = 0;
	arg = NULL;
	while (str[index])
	{
		if (str[index] == ';')
		{
			arg = ft_add_arg(ft_strsub(str, start, index - start), ";", arg);
			start = index + 1;
		}
		else if (str[index] == '|')
		{
			arg = ft_add_arg(ft_strsub(str, start, index - start), "|", arg);
			start = index + 1;
		}
		index++;
	}
	arg = ft_add_arg(ft_strsub(str, start, index - start), ";", arg);
	arg = ft_parser_direct(arg);
	return (arg);
}

int		main(int ac, char **environ)
{
	t_env	env;
	t_dir	dir;
	t_cmd	cmd;
	int		ret;
	t_list	*arg;

	cmd.hist = NULL;
	env.raw = environ;
	process_id = -2;
	ft_signal();
	if (ac > 1)
		return (error(0, NULL));
	if (shell_ini(&cmd, &dir, &env))
		return (-1);
	while (!cmd.exit)
	{
		prompt_display(&dir);
		if (command_get(&cmd) > 0)
		{
			//arg = ft_parser(cmd.raw);
			command_parse(&cmd);
			if (cmd.split[0])
				if ((ret = command_execute(&cmd, &env, &dir)) == -1)
					return (0);
		}
		else
			cmd.exit = 1;
	}
	return (0);
}
