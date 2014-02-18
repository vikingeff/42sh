/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_JUMP.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:45:21 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 20:44:18 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_jump_first(t_cur *cursor, t_char **list)
{
	while (cursor->x != 0)
		k_left(cursor, list);
}

void		k_jump_last(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	while (cursor->x < cmd->len)
		k_right(cmd, cursor, list);
}

void		k_jump_word_prev(t_cur *cursor, t_char **list)
{
	if (*list && (*list)->c == ' ' && (*list)->prev->c)
		k_left(cursor, list);
	while (cursor->x != 0 && (*list)->c != ' ')
		k_left(cursor, list);
}

void		k_jump_word_next(t_cmd *cmd, t_cur *cursor, t_char **list)
{

	if (*list && (*list)->c == ' ' && (*list)->next->c)
		k_right(cmd, cursor, list);
	while (cursor->x < cmd->len && (*list)->c != ' ')
		k_right(cmd, cursor, list);
}