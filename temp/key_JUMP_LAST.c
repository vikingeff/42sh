/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_JUMP_LAST.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:50:26 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 17:55:18 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_jump_last(t_cmd *cmd, int *cursor_pos, t_char **list)
{
	while (*cursor_pos < cmd->len)
		k_right(cmd, cursor_pos, list);
}