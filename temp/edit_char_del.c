/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_char_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:22:36 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:23:05 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_char	*edit_char_del(t_char *list, t_cmd *cmd, int *cursor_pos)
{
	t_char		*list_tmp;

	list_tmp = NULL;
	if (list == NULL)
		return (NULL);
	if (list->next)
	{
		if (list->next->prev)
		{
			list->next->prev = list->prev;
			list_tmp = list->next;
		}
		else
			list->next->prev = NULL;
	}
	if (list->prev)
	{
		if (list->prev->next)
		{
			list->prev->next = list->next;
			list_tmp = list->prev;
		}
		else
			list->prev->next = NULL;
	}
	free (list);
	cmd->len--;
	*cursor_pos -= 1;
	return (list_tmp);
}