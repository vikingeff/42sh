/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_erase_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:00:26 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 13:32:44 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		edit_erase_display(t_cur *cursor)
{
	int		i;

	i = -1;
	while (++i < 100)
		term_put("bt");
	i = 0;
	while (++i < cursor->nb_line)
		term_put("up");
	i = -1;
	while (++i < cursor->nb_line)
		term_put("dl");
}
