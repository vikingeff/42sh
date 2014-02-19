/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_char_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:17:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 16:28:24 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_char	*to_front(t_char **nchr, t_char **lst, t_cmd *cmd, t_cur *cursor);
static void		to_back(t_char **newchar, t_char **list, t_cmd *cmd, t_cur *cursor);

t_char			*edit_char_add(t_char *list, long chr, t_cur *cursor, t_cmd *cmd)
{
	t_char		*newchar;

	newchar = NULL;
	if (!(newchar = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	newchar->c = (int)chr;
	newchar->mirror = 1;
	newchar->nl = 0;
	newchar->next = NULL;
	if (cursor->x == 0)
	{
		newchar->next = list;
		newchar->prev = NULL;
		if (list)
			return (to_front(&newchar, &list, cmd, cursor));
	}
	else
		to_back(&newchar, &list, cmd, cursor);
	cmd->len++;
	cursor->x += 1;
	return (newchar);
}

/*
** add a new char to the front of the existing list
*/

static t_char	*to_front(t_char **nchr, t_char **lst, t_cmd *cmd, t_cur *cursor)
{
	if ((*lst)->prev)
	{
		(*nchr)->prev = (*lst)->prev;
		(*lst)->prev->next = *nchr;
	}
	(*lst)->prev = *nchr;
	(*lst) = *nchr;
	cmd->len++;
	cursor->x += 1;
	return ((*lst));
}

static void		to_back(t_char **newchar, t_char **list, t_cmd *cmd, t_cur *cursor)
{
	if (*list)
	{
		if ((*list)->next)
		{
			(*newchar)->next = (*list)->next;
			(*list)->next->prev = *newchar;
		}
	}
	(*newchar)->prev = *list;
	(*list)->next = *newchar;
	if ((cursor->prompt_len + cmd->len) % cursor->term_len == cursor->term_len--)
		cursor->nb_line -= 1;
}