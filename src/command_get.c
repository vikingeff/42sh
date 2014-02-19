/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 20:45:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 15:18:59 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		edit_ini(t_cur *cursor, t_env *env, t_cmd *cmd, t_char **list);
static void		edit_update(t_env *env, t_cur *cursor, t_cmd *cmd, t_char *list);
static int		is_edit_key(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);
static char		*edit_list_to_str(t_char *list, t_cmd *cmd, t_cur *cursor);

int				command_get(t_env *env, t_cmd *cmd)
{
	t_char		*list;
	t_cur		cursor;

	edit_ini(&cursor, env, cmd, &list);
	ft_putstr("\033[36m");
	edit_line_display(list, &cursor, cmd, env);
	while (!cmd->cmd_end)
	{
		env->key[0] = 0;
		read(0, env->key, 10);
		edit_update(env, &cursor, cmd, list);
		if (!is_edit_key(env->key, cmd, &cursor, &list))
			list = edit_char_add(list, env->key[0], &cursor, cmd);
		if (list && cursor.x > 0)
			list->mirror = 0;
		ft_putstr("\033[36m");
		edit_line_display(list, &cursor, cmd, env);
	}
	if (cmd->raw)
	{
		free(cmd->raw);
		cmd->raw = NULL;
	}
	if (list)
		cmd->raw = edit_list_to_str(list, cmd, &cursor);
	free(env->prompt);
	env->prompt = NULL;
	if (!cmd->raw)
		return (0);
	return (1);
}

static void		edit_ini(t_cur *cursor, t_env *env, t_cmd *cmd, t_char **list)
{
	cursor->x = 0;
	cursor->line_x = 0;
	cursor->y = 1;
	cursor->nb_line = 1;
	cursor->prompt_len = env->prompt_len;
	cursor->term_len = env->term_len;
	cmd->cmd_end = 0;
	cmd->len = 0;
	*list = NULL;
	ft_putstr("\033[7m \033[m");
}

static void		edit_update(t_env *env, t_cur *cursor, t_cmd *cmd, t_char *list)
{
	char	*n_term;

	n_term = env_get_value("TERM", env);
	tgetent(NULL, n_term);
	tcgetattr(0, env->term);
	env->term_len = tgetnum("co");
	cursor->term_len = env->term_len;
	cursor->line_x = (cursor->x + cursor->prompt_len) % cursor->term_len;
	cursor->y = ((cursor->x + cursor->prompt_len) / cursor->term_len) + 1;
	cursor->nb_line = ((cursor->prompt_len + cmd->len) / (cursor->term_len)) + 1;
}

static int		is_edit_key(long key[], t_cmd *cmd, t_cur *cursor, t_char **list)
{
	if (ENTER)
		k_enter(cmd);
	else if (ESC)
		k_esc(cmd);
	else if (LEFT)
		k_left(cursor, list);
	else if (RIGHT)
		k_right(cmd, cursor, list);
	else if (BCKSPC)
		k_bckspc(cmd, cursor, list);
	else if (DEL)
		k_del(cmd, cursor, list);
	else if (UP)
		ft_putendl_fd("\nHISTORIC UP\n", 1);
	else if (DOWN)
		ft_putendl_fd("\nHISTORIC DOWN\n", 1);
	else if (JUMP_FIRST)
		k_jump_first(cursor, list);
	else if (JUMP_LAST)
		k_jump_last(cmd, cursor, list);
	else if (JUMP_WORD_NEXT)
		k_jump_word_next(cmd, cursor, list);
	else if (JUMP_WORD_PREV)
		k_jump_word_prev(cursor, list);
	else if (JUMP_UP)
		k_jump_up(list, cursor, cmd);
	else if (JUMP_DOWN)
		k_jump_down(list, cursor, cmd);
	else
		return (0);
	return (1);
}

static char		*edit_list_to_str(t_char *list, t_cmd *cmd, t_cur *cursor)
{
	char		*str;
	char		*temp;
	t_char		*end;

	str = temp = NULL;
	while (list->next)
		list = list->next;
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
		list = edit_char_del(list, cmd, cursor);
	list = edit_char_del(list, cmd, cursor);
	return (str);
}