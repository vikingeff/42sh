/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:48:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/19 15:19:26 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

extern pid_t		process_id;

static int		command_execve(t_cmd *cmd)
{
	char	*path;
	int		i;

	i = 0;
	path = ft_strdup(cmd->split[0]);
	while (cmd->paths && cmd->paths[i]
		&& execve(path, cmd->split, cmd->env) < 0)
	{
		if (path)
			free(path);
		path = str_join_chr(cmd->paths[i], cmd->split[0], '/');
		i++;
	}
	error(32, cmd->split[0]);
	cmd->split = ft_strsplit("/bin/test", ' ');
	execve(cmd->split[0], cmd->split, NULL);
	return (-1);
}

static int		process_fork(t_cmd *cmd)
{
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

/*
** check if a command is a shell or system and execute them
*/

int				command_execute(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int		ret;

	ret = 0;
	if (!command_get_env(cmd, env, dir))
		if ((ret = command_shell(cmd, env, dir)) < 0)
			ret = process_fork(cmd);
	cmd->ret = ret;
	return (ret);
}

int				command_execute_no_wait(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int		ret;

	ret = 0;
	if (!command_get_env(cmd, env, dir))
		if ((ret = command_shell(cmd, env, dir)) < 0)
			ret = command_execve(cmd);
	if (!cmd->ret)
		cmd->ret = ret;
	return (ret);
}

int				wait_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	return (status);
}