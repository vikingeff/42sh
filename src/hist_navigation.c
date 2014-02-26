/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_navigation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 17:00:00 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/25 16:34:55 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		nav_up(t_cmd *cmd, t_cur *cursor, t_char **list);
static void		nav_down(t_cmd *cmd, t_cur *cursor, t_char **list);

void		hist_navigation(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (UP)
	{
		if (cmd->save_cur == NULL)
		{
			cmd->save_cur = edit_list_to_str(*list, cmd, cursor);
			*list = NULL;
		}
		nav_up(cmd, cursor, list);
	}
	else if (DOWN)
	{
		nav_down(cmd, cursor, list);
	}
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
	{
		cmd->nav = cmd->nav->next;
		while (cmd->nav->data[++i])
		{
			*list = edit_char_add(*list, cmd->nav->data[i], cursor, cmd);
			(*list)->mirror = 0;
		}
	}
	else if (cmd->save_cur)
	{
		while (cmd->save_cur[++i])
		{
			*list = edit_char_add(*list, cmd->save_cur[i], cursor, cmd);
			(*list)->mirror = 0;
		}
		free(cmd->save_cur);
		cmd->save_cur = NULL;
	}
	else
		ft_putstr("\033[7m \033[m");
}