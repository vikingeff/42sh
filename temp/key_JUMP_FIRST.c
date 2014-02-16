/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_JUMP_FIRST.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:45:21 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 17:48:21 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		k_jump_first(int *cursor_pos, t_char **list)
{
	while (*cursor_pos != 0)
		k_left(cursor_pos, list);
}