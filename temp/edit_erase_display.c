/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_erase_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:00:26 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 07:53:41 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** erase the command lines display
*/

void		edit_erase_display(t_cur *cursor)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 100)
		term_put("bt");
	i = 0;
	//usleep(200000);
	while (++i < cursor->nb_line)
	{
		term_put("up");
			//usleep(200000);
	}
	i = -1;
	while (++i < cursor->nb_line)
	{
		term_put("dl");
			//usleep(200000);
	}
}