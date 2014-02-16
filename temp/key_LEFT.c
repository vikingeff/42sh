/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_LEFT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:50:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:05:52 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_left(int *cursor_pos, t_char **list)
{
	if (*cursor_pos > 1)
	{
		*list = (*list)->prev;
		*cursor_pos -= 1;
		term_put("le");
	}
	else if (*cursor_pos == 1)
	{
		*cursor_pos -= 1;
		term_put("le");
	}
}