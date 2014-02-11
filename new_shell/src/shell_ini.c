/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:04:28 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 16:22:44 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** initialise shell data
*/

int		shell_ini(t_cmd *cmd, t_dir *dir, t_env *env)
{
	env->var = env_array_to_list(env);
	cmd->exit = 0;
	cmd->split = NULL;
	cmd->env = NULL;
	if (!(cmd->paths = ft_strsplit(env_get_value("PATH", env), ':')))
		return (-1);
	if (!(dir->pwd = ft_strdup(env_get_value("PWD", env)))
		|| !(dir->oldpwd = ft_strdup(env_get_value("OLDPWD", env)))
		|| !(dir->home = ft_strdup(env_get_value("HOME", env)))
		|| !(dir->user = ft_strdup(env_get_value("USER", env))))
		return (-1);
	return (0);
}