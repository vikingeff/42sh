/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:53:36 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/12 18:25:58 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		setenv_isvalid(t_cmd *cmd, t_env *env);

/*
** setenv <name> <value>
** erase the named env variable value, and replace it with the argument 2
** creates a new variable if it doesn't already exists
*/

int				sh_setenv(t_cmd *cmd, t_env *env)
{
	t_var		*temp;
	t_var		*start;
	t_var		*p_var;

	start = NULL;
	if (setenv_isvalid(cmd, env))
		return (1);
	temp = p_var = env->var;
	while (p_var)
	{
		if (ft_strcmp(cmd->split[1], p_var->name) == 0)
		{
			free(p_var->value);
			p_var->value = (cmd->split[2]) ?
			ft_strdup(cmd->split[2]) : NULL;
			if (cmd->env)
				array2d_free(cmd->env);
			cmd->env = env_list_to_array(env->var, env->nb);
			return (0);
		}
		temp = p_var;
		p_var = p_var->next;
	}
	env_list_add(&temp, &start);
	temp->name = ft_strdup(cmd->split[1]);
	temp->value = (cmd->split[2]) ? ft_strdup(cmd->split[2]) : NULL;
	env->nb++;
	if (cmd->env)
		array2d_free(cmd->env);
	if (env->var == NULL)
		env->var = temp;
	cmd->env = env_list_to_array(env->var, env->nb);
	return (0);
}

/*
** if no arguments, print the env variables
*/

static int		setenv_isvalid(t_cmd *cmd, t_env *env)
{
	int			i;

	i = -1;
	if (!cmd->split[1])
	{
		sh_env(cmd, env, NULL);
		return (1);
	}
	while (cmd->split[1][++i])
		if (cmd->split[1][i] == '=')
			return (error(2, NULL));
	return (0);
}