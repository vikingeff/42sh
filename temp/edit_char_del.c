/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_char_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:22:36 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 22:46:02 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		connection_next(t_char **list, t_char **list_tmp);
static void		connection_prev(t_char **list, t_char **list_tmp);

t_char	*edit_char_del(t_char *list, t_cmd *cmd, t_cur *cursor)
{
	t_char		*list_tmp;

	list_tmp = NULL;
	if (!list)
		return (list);
	if (list->next)
		connection_next(&list, &list_tmp);
	if (list->prev)
		connection_prev(&list, &list_tmp);
	free (list);
	list = NULL;
	cmd->len--;
	cursor->x -= 1;
	return (list_tmp);
}

static void		connection_next(t_char **list, t_char **list_tmp)
{
	if ((*list)->next->prev)
	{
		(*list)->next->prev = (*list)->prev;
		*list_tmp = (*list)->next;
	}
	else
		(*list)->next->prev = NULL;
}

static void		connection_prev(t_char **list, t_char **list_tmp)
{
	if ((*list)->prev->next)
	{
		(*list)->prev->next = (*list)->next;
		*list_tmp = (*list)->prev;
	}
	else
		(*list)->prev->next = NULL;
}