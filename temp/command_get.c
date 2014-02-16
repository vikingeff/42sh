/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:45:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:07:11 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		key_edition(int key[], t_cmd *cmd, int *cursor_pos, t_char **list);
static char		*list_to_str(t_char *list, t_cmd *cmd, int *cursor_pos);

int				command_get(t_env *env, t_cmd *cmd)
{
	t_char		*list;
	int			cursor_pos;
	char		*temp;

	cmd->cmd_end = 0;
	cmd->len = 0;
	list = NULL;
	cursor_pos = 0;
	while (!cmd->cmd_end)
	{
		env->key[0] = 0;
		read(0, env->key, 10);
		if (!key_edition(env->key, cmd, &cursor_pos, &list))
		{
			list = char_add(list, env->key[0], &cursor_pos, cmd);
			ft_putchar(env->key[0]);
		}
	}
	if (cmd->raw)
	{
		free(cmd->raw);
		cmd->raw = NULL;
	}
	if (list)
		cmd->raw = list_to_str(list, cmd, &cursor_pos);
	return (0);
}

static int		key_edition(int key[], t_cmd *cmd, int *cursor_pos, t_char **list)
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
		ft_putendl_fd("HISTORIC UP", 1);
	else if (DOWN)
		ft_putendl_fd("HISTORIC DOWN", 1);
	else
		return (0);
	return (1);
}

t_char	*char_add(t_char *list, int chr, int *cursor_pos, t_cmd *cmd)
{
	t_char		*newchar;

	newchar = NULL;
	if (!(newchar = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	newchar->c = chr;
	newchar->next = NULL;
	if (*cursor_pos == 0)
	{
		newchar->next = list;
		newchar->prev = NULL;
		if (list)
		{
			if (list->prev)
			{
				newchar->prev = list->prev;
				list->prev->next = newchar;
			}
			list->prev = newchar;
			list = newchar;
			cmd->len++;
			*cursor_pos += 1;
			return (list);
		}
	}
	else
	{
		if (list->next)
		{
			newchar->next = list->next;
			list->next->prev = newchar;
		}
		newchar->prev = list;
		list->next = newchar;
	}
	cmd->len++;
	*cursor_pos += 1;
	return (newchar);
}

t_char	*char_del(t_char *list, t_cmd *cmd, int *cursor_pos)
{
	t_char		*list_tmp;

	list_tmp = NULL;
	if (list == NULL)
		return (NULL);
	if (list->next)
	{
		if (list->next->prev)
		{
			list->next->prev = list->prev;
			list_tmp = list->next;
		}
		else
			list->next->prev = NULL;
	}
	if (list->prev)
	{
		if (list->prev->next)
		{
			list->prev->next = list->next;
			list_tmp = list->prev;
		}
		else
			list->prev->next = NULL;
	}
	free (list);
	cmd->len--;
	*cursor_pos -= 1;
	return (list_tmp);
}

static char		*list_to_str(t_char *list, t_cmd *cmd, int *cursor_pos)
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
		list = char_del(list, cmd, cursor_pos);
	list = char_del(list, cmd, cursor_pos);
	return (str);
}