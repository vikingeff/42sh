/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 21:16:23 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/05 16:44:44 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** make an instance of current environnement that can be modified 
** before execution with the env builtin without changing the current env
*/

int		command_get_env(t_cmd *cmd, t_env *env)
{
	if (cmd->env)
		array2d_free(cmd->env);
	if (!(cmd->env = env_list_to_array(env->var, env->nb)))
		return (-1);
	return (0);
}