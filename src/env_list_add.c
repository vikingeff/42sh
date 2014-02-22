/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:29:27 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/12 17:49:45 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** add a node to env list.
**
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