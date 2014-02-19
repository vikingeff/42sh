/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_LEFT.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 15:50:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 23:12:53 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_left(t_cur *cursor, t_char **list)
{
	if (cursor->x > 1)
	{
		(*list)->mirror = 1;
		if ((*list)->next)
			(*list)->next->mirror = 0;
		*list = (*list)->prev;
		cursor->x -= 1;
	}
	else if (cursor->x == 1)
	{
		if ((*list)->next)
			(*list)->next->mirror = 0;
		(*list)->mirror = 1;
		cursor->x -= 1;
	}
}