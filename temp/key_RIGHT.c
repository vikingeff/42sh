/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_RIGHT.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:54:22 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:17:24 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_right(t_cmd *cmd, int *cursor_pos, t_char **list)
{
	if (*cursor_pos >= 1 && *cursor_pos < cmd->len)
	{
		*cursor_pos += 1;
		*list = (*list)->next;
		term_put("nd");
	}
	else if (*cursor_pos == 0)
	{
		*cursor_pos += 1;
		term_put("nd");
	}
}