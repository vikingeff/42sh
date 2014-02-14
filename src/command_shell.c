/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:53:59 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 19:44:39 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** check if the current command is a shell built-in command 
** and execute it if so. 
** Return 1 if the command was an built-in or 0 in the opposite case.
*/

int			command_shell(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(cmd->split[0], "exit") == 0)
		sh_exit(cmd);
	else if (ft_strcmp(cmd->split[0], "env") == 0)
		sh_env(cmd, env, dir);
	else if (ft_strcmp(cmd->split[0], "unsetenv") == 0
		|| ft_strcmp(cmd->split[0], "unset") == 0)
		sh_unsetenv(cmd, env);
	else if (ft_strcmp(cmd->split[0], "setenv") == 0
		|| ft_strcmp(cmd->split[0], "export") == 0)
		sh_setenv(cmd, env);
	else if (ft_strcmp(cmd->split[0], "cd") == 0)
		sh_cd(cmd, env, dir);
	else if (ft_strcmp(cmd->split[0], "echo") == 0)
		ret = sh_echo(cmd, env, dir);
	else
		ret = -1;
	return (ret);
}