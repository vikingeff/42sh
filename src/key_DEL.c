/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_DEL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:38:10 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 23:21:14 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_del(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (cmd->len > 0 && cursor->x < cmd->len)
	{
		k_right(cmd, cursor, list);
		k_bckspc(cmd, cursor, list);
	}
}