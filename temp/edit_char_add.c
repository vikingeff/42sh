/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_char_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:17:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:17:36 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_char	*edit_char_add(t_char *list, int chr, int *cursor_pos, t_cmd *cmd)
{
	t_char		*newchar;

	newchar = NULL;
	if (!(newchar = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	newchar->c = chr;
	newchar->next = NULL;
	if (*cursor_pos == 0)
	{
		newchar->next = list;
		newchar->prev = NULL;
		if (list)
		{
			if (list->prev)
			{
				newchar->prev = list->prev;
				list->prev->next = newchar;
			}
			list->prev = newchar;
			list = newchar;
			cmd->len++;
			*cursor_pos += 1;
			return (list);
		}
	}
	else
	{
		if (list->next)
		{
			newchar->next = list->next;
			list->next->prev = newchar;
		}
		newchar->prev = list;
		list->next = newchar;
	}
	cmd->len++;
	*cursor_pos += 1;
	return (newchar);
}