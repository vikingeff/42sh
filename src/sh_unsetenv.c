/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:29:36 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/15 19:17:42 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		cell_delete(t_var *var, t_var *prev);
static t_var	*cell_first_delete(t_var *p_var, t_var **prev);

/*
** erase minishell env variables given as arguments
** return 0 if no error or -1 if the variable doesn't exist or cannot be unset
** because it is used by minishell.
*/

int				sh_unsetenv(t_cmd *cmd, t_env *env)
{
	t_var		*prev;
	t_var		*p_var;

	p_var = env->var;
	prev = NULL;
	while (p_var)
	{
		if (ft_strcmp(cmd->split[1], p_var->name) == 0)
		{
			if (!prev)
				p_var = cell_first_delete(p_var, &prev);
			else
				cell_delete(p_var, prev);
			array2d_free(cmd->env);
			env->nb--;
			if (!p_var)
				env->var = prev;
			cmd->env = env_list_to_array(env->var, env->nb);
			return (0);
		}
		prev = p_var;
		p_var = p_var->next;
	}
	error(30, cmd->split[1]);
	return (256);
}

static void		cell_delete(t_var *p_var, t_var *prev)
{
	prev->next = p_var->next;
	free(p_var->name);
	free(p_var->value);
	free(p_var);
	p_var = NULL;
}

static t_var	*cell_first_delete(t_var *p_var, t_var **prev)
{
	*prev = p_var->next;
	free(p_var->name);
	free(p_var->value);
	free(p_var);
	p_var = NULL;
	return (p_var);
}