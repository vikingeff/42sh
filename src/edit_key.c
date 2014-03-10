/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:42:25 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/28 16:58:04 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	e_completion(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);
static int	e_edition(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);
static int	e_navigation(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);

/*
** Welcome to the secret IF forest !
** check if the given key is an "edition key" and execute the associate action.
** Return 1 if the key is a edition key and 0 in the opposite case.
*/

int			edit_key(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (e_completion(key, cmd, cursor, list))
		return (1);
	else if (e_edition(key, cmd, cursor, list))
		return (1);
	else if (e_navigation(key, cmd, cursor, list))
		return (1);
	return (0);
}

static int	e_completion(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (TAB)
	{
		completion(cmd, cursor, list, 1);
		return (1);
	}
	reset_comp(cmd);
	return (0);
}

static int	e_edition(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (ENTER)
		k_enter(cmd);
	else if (ESC)
		k_esc(cmd);
	else if (BCKSPC)
		k_bckspc(cmd, cursor, list);
	else if (DEL)
		k_del(cmd, cursor, list);
	else
		return (0);
	return (1);
}

static int	e_navigation(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (LEFT)
		k_left(cursor, list);
	else if (RIGHT)
		k_right(cmd, cursor, list);
	else if (UP || DOWN)
		hist_navig(key, cmd, cursor, list);
	else if (JUMP_FIRST)
		k_jump_first(cursor, list);
	else if (JUMP_LAST)
		k_jump_last(cmd, cursor, list);
	else if (JUMP_WORD_NEXT)
		k_jump_word_next(cmd, cursor, list);
	else if (JUMP_WORD_PREV)
		k_jump_word_prev(cursor, list);
	else if (JUMP_UP)
		k_jump_up(list, cursor, cmd);
	else if (JUMP_DOWN)
		k_jump_down(list, cursor, cmd);
	else
		return (0);
	return (1);
}
