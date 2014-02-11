/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 22:00:39 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/07 22:54:21 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		env_list_create(t_cmd *cmd, t_env *env)
{
	t_var		*node;

	node = (t_var *)malloc(sizeof(t_var));
	node->next = NULL;
	node->name = ft_strdup(cmd->split[1]);
	node->value = (cmd->split[2]) ? ft_strdup(cmd->split[2]) : NULL;
	env->var = node;
	env->nb = 1;
	cmd->env = env_list_to_array(env->var, env->nb);
}