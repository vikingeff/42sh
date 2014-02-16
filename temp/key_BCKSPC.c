/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_BCKSPC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:58:46 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:05:54 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_bckspc(t_cmd *cmd, int *cursor_pos, t_char **list)
{
	if (*cursor_pos >= 1)
	{
		term_put("le");
		term_put("dc");
		*list = char_del(*list, cmd, cursor_pos);
	}
}