/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:04:28 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 17:40:13 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** initialise shell data
*/

int		shell_ini(t_cmd *cmd, t_dir *dir, t_env *env)
{
	char	buff[2048];

	env->var = env_array_to_list(env);
	cmd->exit = 0;
	cmd->split = NULL;
	cmd->env = NULL;
	cmd->raw = NULL;
	cmd->alias = NULL;
	cmd->ret = 0;
	if (!(cmd->paths = ft_strsplit(env_get_value("PATH", env), ':')))
		return (-1);
	if (!(dir->pwd = ft_strdup(getcwd(buff, 2048)))
		|| !(dir->oldpwd = ft_strdup(env_get_value("OLDPWD", env)))
		|| !(dir->home = ft_strdup(env_get_value("HOME", env)))
		|| !(dir->user = ft_strdup(env_get_value("USER", env))))
		return (-1);
	return (0);
}