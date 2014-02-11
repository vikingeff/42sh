/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:48:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 15:49:57 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		process_fork(t_cmd *cmd);
static int		command_execve(t_cmd *cmd);
static int		wait_process(pid_t pid);

/*
** check if a command is a shell or system and execute them
*/

int				command_execute(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int		ret;

	ret = 0;
	if (!command_get_env(cmd, env))
		if (command_shell(cmd, env, dir) == 0)
			ret = process_fork(cmd);
	return (ret);
}

static int		process_fork(t_cmd *cmd)
{
	pid_t		process_id;
	int			i;
	int			ret;

	process_id = fork();
	if (process_id > 0)
		ret = wait_process(process_id);
	else if (process_id == 0)
	{
		if (command_execve(cmd))
			return (-1);
	}
	return (ret);
}

static int		command_execve(t_cmd *cmd)
{
	char	*path;
	int		i;

	i = 0;
	path = ft_strdup(cmd->split[0]);
	while (execve(path, cmd->split, cmd->env) < 0 && cmd->paths[i])
	{
		if (path)
			free(path);
		path = str_join_chr(cmd->paths[i], cmd->split[0], '/');
		i++;
	}
	error(32, cmd->split[0]);
	return (-1);
}

static int		wait_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	return (status);
}