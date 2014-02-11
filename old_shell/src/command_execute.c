/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:48:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/07 22:59:33 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		process_fork(t_cmd *cmd);
static int		command_execve(t_cmd *cmd);
static void		wait_process(pid_t pid);

/*
** check if a command is a shell or system and execute them
*/

int				command_execute(t_cmd *cmd, t_env *env, t_dir *dir)
{
	if (!command_get_env(cmd, env))
		if (command_shell(cmd, env, dir) == 0)
			if (process_fork(cmd))
				return (-1);
	return (0);
}

static int		process_fork(t_cmd *cmd)
{
	pid_t		process_id;
	int			i;

	process_id = fork();
	if (process_id > 0)
		wait_process(process_id);
	else if (process_id == 0)
	{
		if (command_execve(cmd))
			return (-1);
	}
	return (0);
}

static int		command_execve(t_cmd *cmd)
{
	char	*path;
	int		i;

	i = 0;
	path = cmd->split[0];
	while (execve(path, cmd->split, cmd->env) < 0 && cmd->paths[i])
	{
		if (!path)
			free(path);
		path = str_join_chr(cmd->paths[i], cmd->split[0], '/');
		i++;
	}
	error(32, cmd->split[0]);
	return (-1);
}

static void		wait_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
}