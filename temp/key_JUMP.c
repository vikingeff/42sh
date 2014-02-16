/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_JUMP.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:45:21 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 18:46:07 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_jump_first(int *cursor_pos, t_char **list)
{
	while (*cursor_pos != 0)
		k_left(cursor_pos, list);
}

void		k_jump_last(t_cmd *cmd, int *cursor_pos, t_char **list)
{
	while (*cursor_pos < cmd->len)
		k_right(cmd, cursor_pos, list);
}

void		k_jump_word_prev(int *cursor_pos, t_char **list)
{
	if (*list && (*list)->c == ' ' && (*list)->prev->c)
		k_left(cursor_pos, list);
	while (*cursor_pos != 0 && (*list)->c != ' ')
		k_left(cursor_pos, list);
}

void		k_jump_word_next(t_cmd *cmd, int *cursor_pos, t_char **list)
{

	if (*list && (*list)->c == ' ' && (*list)->next->c)
		k_right(cmd, cursor_pos, list);
	while (*cursor_pos < cmd->len && (*list)->c != ' ')
		k_right(cmd, cursor_pos, list);
}