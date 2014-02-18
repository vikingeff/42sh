/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:18:03 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/18 17:50:00 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_special_char(char c)
{
	if (c == '$' || c == '`' || c == '"' || c == '\\' || c == '\n')
		return (1);
	return (0);
}

static int		ft_avoid_char(char c)
{
	if (c == '$' || c == '`')
		return (1);
	return (0);
}

static int		ft_inib(t_cmd *cmd, int index, int rule)
{
	while (cmd->raw[index])
	{
		if ((cmd->raw[index] == '\'' || cmd->raw[index] == '\"')
			&& (!rule || rule == cmd->raw[index]))
		{
			if (!rule)
				rule = cmd->raw[index];
			else
				rule = 0;
			ft_delete_char(cmd, index);
		}
		if (cmd->raw[index] == '\\'&& (!rule
			|| (rule == '\"' && ft_special_char(cmd->raw[index + 1]))))
		{
			ft_delete_char(cmd, index);
			if (cmd->raw[index] != '\n')
				cmd->raw[index] = - 1 * cmd->raw[index];
			else
				ft_delete_char(cmd, index);
		}
		if (rule == '\'' || (rule == '\"' && !ft_avoid_char(cmd->raw[index])))
			cmd->raw[index] = - 1 * cmd->raw[index];
		index++;
	}
	return (rule);
}

int				ft_get_backquote(t_cmd *cmd, int index, int rule)
{
	while (cmd->raw[index])
	{
		if ((cmd->raw[index] == '`')
			&& (!rule || rule == cmd->raw[index]))
		{
			if (!rule)
				rule = cmd->raw[index];
			else
				rule = 0;
			index++;
		}
		if (rule)
			cmd->raw[index] = - 1 * cmd->raw[index];
		index++;
	}
	return (rule);

}

int				ft_inib_starter(t_cmd *cmd)
{
	int		rule;
	int		index;
	char	buf[2];

	buf[1] = 0;
	rule = 0;
	index = 0;
	rule = ft_inib(cmd, index, rule);
	if (rule)
	{
		buf[0] = rule;
		error(4, buf);
		cmd->ret = 1;
		return (rule);
	}
	rule = 0;
	index = 0;
	rule = ft_get_backquote(cmd, index, rule);
	if (rule)
	{
		buf[0] = rule;
		cmd->ret = 1;
		error(4, buf);
	}
	return (rule);
}
