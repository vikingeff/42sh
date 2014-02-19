/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_RIGHT.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:54:22 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 09:31:59 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_right(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (cursor->x >= 1 && cursor->x < cmd->len)
	{
		if ((*list)->next)
		{
			(*list)->next->mirror = 0;
			if ((*list)->next->next)
				(*list)->next->next->mirror = 1;
			cursor->x += 1;
			*list = (*list)->next;
		}
	}
	else if (cursor->x == 0)
	{
		if (*list)
		{
			(*list)->mirror = 0;
			if ((*list)->next)
				(*list)->next->mirror = 1;
			cursor->x += 1;
		}
	}
}