/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:53:59 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/07 13:40:33 by cobrecht         ###   ########.fr       */
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
	if (ft_strcmp(cmd->split[0], "exit") == 0)
		sh_exit(cmd);
	else if (ft_strcmp(cmd->split[0], "env") == 0)
		sh_env(cmd, env);
	else if (ft_strcmp(cmd->split[0], "unsetenv") == 0)
		sh_unsetenv(cmd, env);
	else if (ft_strcmp(cmd->split[0], "setenv") == 0)
		sh_setenv(cmd, env);
	else if (ft_strcmp(cmd->split[0], "cd") == 0)
		sh_cd(cmd, env, dir);
	else
		return (0);
	return (1);
}