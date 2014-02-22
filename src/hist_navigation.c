/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_navigation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 17:00:00 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 20:43:19 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		nav_up(t_cmd *cmd, t_cur *cursor, t_char **list);
static void		nav_down(t_cmd *cmd, t_cur *cursor, t_char **list);

void		hist_navigation(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (UP)
		nav_up(cmd, cursor, list);
	else if (DOWN)
		nav_down(cmd, cursor, list);
}

static void		nav_up(t_cmd *cmd, t_cur *cursor, t_char **list)
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
}

static void		nav_down(t_cmd *cmd, t_cur *cursor, t_char **list)
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
}