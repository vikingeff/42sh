/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:18:03 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/15 19:16:18 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_delete_char(t_cmd *cmd, int index)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strsub(cmd->raw, 0, index);
	tmp2 = ft_strsub(cmd->raw, index + 1, ft_strlen(cmd->raw) - (index + 1));
	free(cmd->raw);
	cmd->raw = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

static int		ft_special_char(char c)
{
	if (c == '$' || c == '`' || c == '"' || c == '\\' || c == '\n')
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
		if (rule == '\'' || (rule == '\"' && cmd->raw[index] != '$'))
			cmd->raw[index] = - 1 * cmd->raw[index];
		index++;
	}
	return (rule);
}

int				ft_inib_starter(t_cmd *cmd)
{
	int	rule;
	int	index;

	rule = 0;
	index = 0;
	rule = ft_inib(cmd, index, rule);
	return (rule);
}
