/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 18:16:25 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/27 09:14:09 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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
