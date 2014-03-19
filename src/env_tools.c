/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:53:04 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/19 16:18:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** convert env *list into env **array for excve() use
** if var->temp !NULL, the variable will be set to temp
*/

char			**env_list_to_array(t_var *var, int size)
{
	char		**array;
	t_var		*start;
	int			i;

	i = 0;
	array = NULL;
	start = var;
	if ((array = (char**)malloc(sizeof(char*) * size)))
	{
		while (i < (size - 1))
		{
			array[i] = str_join_chr(var->name, var->value, '=');
			var = var->next;
			i++;
		}
		array[i] = NULL;
		var = start;
	}
	return (array);
}

/*
** add a node to env list.
*/

int		env_list_add(t_var **list, t_var **start)
{
	t_var		*node;

	if ((node = (t_var*)malloc(sizeof(t_var))) == NULL)
		return (error(15, "env_list_add ()"));
	node->next = NULL;
	if (*list == NULL)
		*start = *list = node;
	else
	{
		(*list)->next = node;
		*list = node;
	}
	return (0);
}

char			*env_get_value(char *name, t_env *env)
{
	t_var	*temp;

	temp = env->var;
	while (temp)
	{
		if (ft_strcmp(name, temp->name) == 0)
		{
			if (!temp->value[0])
				error(31, name);
			return (temp->value);
		}
		temp = temp->next;
	}
	error(30, name);
	return (NULL);
}