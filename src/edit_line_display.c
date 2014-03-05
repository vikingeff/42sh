/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 17:57:50 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/28 16:43:02 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	refresh_line(t_env *env, t_cur *cur);
static int	stop_display(t_cmd *cmd);

void		edit_line_display(t_char *list, t_cur *cur, t_cmd *cmd, t_env *env)
{
	int		cur_diff;
	t_char	*start;

	refresh_line(env, cur);
	if (!list)
		if (stop_display(cmd))
			return ;
	cur_diff = 0;
	start = list;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		if (list->mirror == 1 && !cmd->cmd_end)
			term_put("mr");
		ft_putchar(list->c);
		term_put("me");
		list = list->next;
	}
	if (cur->x == cmd->len && !cmd->cmd_end)
		ft_putstr("\033[7m \033[m");
	if (cmd->cmd_end == 1)
		ft_putchar('\n');
}

static void		refresh_line(t_env *env, t_cur *cur)
{
	ft_putstr("\033[1;34m");
	edit_erase_display(cur);
	ft_putstr(env->prompt);
	ft_putstr("\033[m");
}

static int		stop_display(t_cmd *cmd)
{
	if (!cmd->cmd_end)
		ft_putstr("\033[7m \033[m");
	return (1);
}