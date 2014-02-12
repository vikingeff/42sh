/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:53:04 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/05 16:44:45 by cobrecht         ###   ########.fr       */
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