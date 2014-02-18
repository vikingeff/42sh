/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_erase_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:00:26 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 22:32:50 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** erase the command lines display
*/

void		edit_erase_display(t_cur *cursor)
{
	int		i;

	i = 0;
	term_put("rc");
	term_put("dl");
	if (cursor->line_x == 0)
		term_put("up");
	while (++i < cursor->nb_line && cursor->line_x != 0)
	{
		term_put("up");
		term_put("dl");
	}
}