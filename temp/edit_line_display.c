/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 17:57:50 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 23:35:22 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	edit_line_display(t_char *list, t_cur *cursor, t_cmd *cmd, t_env *env)
{
	int		cursor_diff;
	t_char	*start;

	edit_erase_display(cursor);
	ft_putstr(env->prompt);
	if (!list)
	{
		ft_putstr("\033[7m \033[m");
		return ;
	}
	cursor_diff = 0;
	start = list;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		if (list->mirror == 1)
			term_put("mr");
		ft_putchar(list->c);
		term_put("me");
		list = list->next;
	}
	if (cursor->x == cmd->len)
		ft_putstr("\033[7m \033[m");
}