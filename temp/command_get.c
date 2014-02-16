/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:45:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 17:54:32 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		edit_key(int key[], t_cmd *cmd, int *cursor_pos, t_char **list);
static char		*edit_list_to_str(t_char *list, t_cmd *cmd, int *cursor_pos);

int				command_get(t_env *env, t_cmd *cmd)
{
	t_char		*list;
	int			cursor_pos;

	cmd->cmd_end = 0;
	cmd->len = 0;
	list = NULL;
	cursor_pos = 0;
	while (!cmd->cmd_end)
	{
		env->key[0] = 0;
		read(0, env->key, 10);
		if (!edit_key(env->key, cmd, &cursor_pos, &list))
		{
			list = edit_char_add(list, env->key[0], &cursor_pos, cmd);
			ft_putchar(env->key[0]);
		}
	}
	if (cmd->raw)
	{
		free(cmd->raw);
		cmd->raw = NULL;
	}
	if (list)
		cmd->raw = edit_list_to_str(list, cmd, &cursor_pos);
	return (0);
}

static int		edit_key(int key[], t_cmd *cmd, int *cursor_pos, t_char **list)
{
	if (ENTER)
		k_enter(cmd);
	else if (ESC)
		k_esc(cmd);
	else if (LEFT)
		k_left(cursor_pos, list);
	else if (RIGHT)
		k_right(cmd, cursor_pos, list);
	else if (BCKSPC)
		k_bckspc(cmd, cursor_pos, list);
	else if (UP)
		ft_putendl_fd("\nHISTORIC UP\n", 1);
	else if (DOWN)
		ft_putendl_fd("\nHISTORIC DOWN\n", 1);
	else if (JUMP_FIRST)
		k_jump_first(cursor_pos, list);
	else if (JUMP_LAST)
		k_jump_last(cmd, cursor_pos, list);
	else if (DEL)
		k_del(cmd, cursor_pos, list);
	else
		return (0);
	return (1);
}

static char		*edit_list_to_str(t_char *list, t_cmd *cmd, int *cursor_pos)
{
	char		*str;
	char		*temp;
	t_char		*end;

	temp = NULL;
	str = NULL;
	end = list;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		if (str)
			free(str);
		str = ft_strjoin(temp, &list->c);
		if (temp)
			free(temp);
		temp = ft_strdup(str);
		list = list->next;
	}
	free(temp);
	list = end;
	while (list->prev)
		list = edit_char_del(list, cmd, cursor_pos);
	list = edit_char_del(list, cmd, cursor_pos);
	return (str);
}