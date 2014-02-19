/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_JUMP_LINE.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 08:09:51 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 10:26:49 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_jump_up(t_char **list, t_cur *cursor, t_cmd *cmd)
{
	int		i;

	i = -1;
	if (!list)
		return ;
	while (++i < cursor->term_len && cursor->x > 0)
	{
		if (cursor->x != cmd->len && (*list)->next)
			(*list)->next->mirror = 0;
		cursor->x -= 1;
		if (cursor->x > 0 && (*list)->prev)
			*list = (*list)->prev;
	}
	if ((*list)->next && cursor->x > 0)
		(*list)->next->mirror = 1;
	else
		(*list)->mirror = 1;
}

void		k_jump_down(t_char **list, t_cur *cursor, t_cmd *cmd)
{
	int		i;

	i = -1;
	if (!list)
		return ;
	if (cursor->x == 0)
		cursor->x = 1;
	while (++i < cursor->term_len && cursor->x < cmd->len)
	{
		(*list)->mirror = 0;
		cursor->x += 1;
		if ((*list)->next)
			*list = (*list)->next;
	}
	if (cursor->x != cmd->len && (*list)->next)
		(*list)->next->mirror = 1;
}