/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_char_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:17:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 17:11:27 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_char	*to_front(t_char **nchr, t_char **lst, t_cmd *cmd, int *c_pos);
static void		to_back(t_char **newchar, t_char **list);

t_char			*edit_char_add(t_char *list, int chr, int *c_pos, t_cmd *cmd)
{
	t_char		*newchar;

	newchar = NULL;
	if (!(newchar = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	newchar->c = chr;
	newchar->next = NULL;
	if (*c_pos == 0)
	{
		newchar->next = list;
		newchar->prev = NULL;
		if (list)
			return (to_front(&newchar, &list, cmd, c_pos));
	}
	else
		to_back(&newchar, &list);
	cmd->len++;
	*c_pos += 1;
	return (newchar);
}

/*
** add a new char to the front of the existing list
*/

static t_char	*to_front(t_char **nchr, t_char **lst, t_cmd *cmd, int *c_pos)
{
	if ((*lst)->prev)
	{
		(*nchr)->prev = (*lst)->prev;
		(*lst)->prev->next = *nchr;
	}
	(*lst)->prev = *nchr;
	(*lst) = *nchr;
	cmd->len++;
	*c_pos += 1;
	return ((*lst));
}

static void		to_back(t_char **newchar, t_char **list)
{
	if ((*list)->next)
	{
		(*newchar)->next = (*list)->next;
		(*list)->next->prev = *newchar;
	}
	(*newchar)->prev = *list;
	(*list)->next = *newchar;
}