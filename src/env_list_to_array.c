/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:53:04 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:14:12 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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
