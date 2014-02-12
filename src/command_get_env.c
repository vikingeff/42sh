/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 21:16:23 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/12 12:01:20 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** make an instance of current environnement that can be modified 
** before execution with the env builtin without changing the current env
*/

int		command_get_env(t_cmd *cmd, t_env *env, t_dir *dir)
{
	if (cmd->env)
		array2d_free(cmd->env);
	if (!(cmd->env = env_list_to_array(env->var, env->nb)))
		return (-1);
	cmd->paths = ft_strsplit(env_get_value("PATH", env), ':');
	dir->home = ft_strdup(env_get_value("HOME", env));
	dir->user = ft_strdup(env_get_value("USER", env));
	return (0);
}