/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:46:47 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/05 16:21:13 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(int ac, char **environ)
{
	t_env	env;
	t_dir	dir;
	t_cmd	cmd;

	env.raw = environ;
	if (ac > 1)
		return (error(0, NULL));
	if (shell_ini(&cmd, &dir, &env))
		return (-1);
	while (!cmd.exit)
	{
		prompt_display(&dir);
		if (command_get(&cmd) > 0)
		{
			command_parse(&cmd);
			if (cmd.split[0])
				if (command_execute(&cmd, &env, &dir))
					return (0);
		}
	}
	return (0);
}
