/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_navigation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 17:00:00 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 19:44:34 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		hist_navigation_up(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	int		i;
	char	*trash;

	i = -1;
	if (!cmd->nav)
		return ;
	if (*list)
	{
		trash = edit_list_to_str(*list, cmd, cursor);
		free(trash);
		*list = NULL;
	}
	while (cmd->nav->data[++i])
	{
		*list = edit_char_add(*list, cmd->nav->data[i], cursor, cmd);
		(*list)->mirror = 0;
	}
	if (cmd->nav->prev)
		cmd->nav = cmd->nav->prev;
	cmd->nav_move = 1;
}

void		hist_navigation_down(t_cmd *cmd, t_cur *cursor, t_char **list)
{
	int		i;
	char	*trash;

	i = -1;
	if (!cmd->nav)
		return ;
	if (*list)
	{
		trash = edit_list_to_str(*list, cmd, cursor);
		free(trash);
		*list = NULL;
	}
	if (cmd->nav->next)
		cmd->nav = cmd->nav->next;
	while (cmd->nav->data[++i])
	{
		*list = edit_char_add(*list, cmd->nav->data[i], cursor, cmd);
		(*list)->mirror = 0;
	}
	cmd->nav_move = 1;
}