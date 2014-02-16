/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_DEL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:38:10 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 17:44:36 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_del(t_cmd *cmd, int *cursor_pos, t_char **list)
{
	if (cmd->len > 0 && *cursor_pos < cmd->len)
	{
		k_right(cmd, cursor_pos, list);
		k_bckspc(cmd, cursor_pos, list);
	}
}