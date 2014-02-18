/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_BCKSPC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:58:46 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 23:22:42 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_bckspc(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (cursor->x > 1)
	{
		(*list)->mirror = 0;
		if ((*list)->prev)
			(*list)->prev->mirror = 1;
		*list = edit_char_del(*list, cmd, cursor);
	}
	else if (cursor->x == 1)
	{
		*list = edit_char_del(*list, cmd, cursor);
	}

}