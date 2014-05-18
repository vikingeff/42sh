/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 17:29:27 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:14:13 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		env_list_add(t_var **list, t_var **start)
{
	t_var		*node;

	node = (t_var*)malloc(sizeof(t_var));
	if (node == NULL)
		return (error(15, "env_list_add ()"));
	node->next = NULL;
	if (*list == NULL)
	{
		*list = node;
		*start = *list;
	}
	else
	{
		(*list)->next = node;
		*list = node;
	}
	return (0);
}
