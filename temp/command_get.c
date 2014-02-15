/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:45:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/15 21:19:02 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		key_edition(int key[], t_cmd *cmd, t_char **start, t_char **list);
static t_char	*char_add(t_char *list, int chr, t_char **start);
static t_char	*char_del(t_char *list);
static char		*list_to_str(t_char *list);

int				command_get(t_env *env, t_cmd *cmd)
{
	t_char		*list;
	t_char		*start;

	cmd->cmd_end = 0;
	list = NULL;
	start = NULL;
	while (!cmd->cmd_end)
	{
		env->key[0] = 0;
		read(0, env->key, 3);
		if (!key_edition(env->key, cmd, &start, &list))
		{
			list = char_add(list, env->key[0], &start);
			ft_putchar(env->key[0]);
		}
	}
	if (cmd->raw)
		free(cmd->raw);
	if (list)
		cmd->raw = list_to_str(list);
	return (0);
}

static int		key_edition(int key[], t_cmd *cmd, t_char **start, t_char **list)
{

	if (ENTER)
		cmd->cmd_end = 1;
	else if (ESC)
	{
		cmd->cmd_end = 1;
		cmd->exit = 1;
	}
	else if (UP)
		ft_putendl_fd("UP", 1);
	else if (DOWN)
		ft_putendl_fd("DOWN", 1);
	else if (LEFT)
	{
		if ((*list)->prev)
		{
			*list = (*list)->prev;
			term_put("le");
		}
		else
		{
			if (!*start)
				term_put("le");
			*start = *list;
		}
	}
	else if (RIGHT)
	{
		if (*start)
		{
			*start = NULL;
			term_put("nd");
		}
		else if ((*list)->next)
		{
			*list = (*list)->next;
			term_put("nd");
		}
	}
	else if (BCKSPC)
	{
		if ((*list)->prev)
		{
			term_put("le");
			term_put("dc");
			*list = char_del(*list);
		}
	}
	else
		return (0);

	return (1);
}

static t_char	*char_add(t_char *list, int chr, t_char **start)
{
	t_char		*newchar;

	newchar = NULL;
	if (!(newchar = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	newchar->c = chr;
	newchar->next = NULL;
	if (*start)
	{
		newchar->next = list;
		newchar->prev = NULL;
		if (list->prev)
		{
			newchar->prev = list->prev;
			list->prev->next = newchar;
		}
		list->prev = newchar;
		*start = NULL;
		return (list);
	}
	else if (list)
	{
		if (list->next)
		{
			newchar->next = list->next;
			list->next->prev = newchar;
		}
		newchar->prev = list;
		list->next = newchar;
	}
	else
		newchar->prev = NULL;
	return (newchar);
}

static t_char	*char_del(t_char *list)
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
	return (list_tmp);
}

static char		*list_to_str(t_char *list)
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
	list = end;
	while (list->prev)
		list = char_del(list);
	list = char_del(list);
	return (str);
}