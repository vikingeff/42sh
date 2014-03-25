/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 14:17:47 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/18 16:02:25 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void			ft_put_alias(t_cmd *cmd)
{
	t_list	*alias;

	alias = cmd->alias;
	while (alias)
	{
		ft_putstr(alias->mot);
		ft_putstr(" (");
		ft_putstr(alias->valeure);
		ft_putstr(")\n");
		alias = alias->next;
	}
}

static void			ft_put_one_alias(t_cmd *cmd)
{
	t_list	*alias;

	alias = ft_find_list(cmd->alias, cmd->split[1]);
	if (alias)
		ft_putendl(alias->valeure);
}

static int			alias_isvalid(t_cmd *cmd)
{
	int			i;

	i = -1;
	if (!cmd->split[1] || cmd->split[1][0] == '\0')
	{
		ft_put_alias(cmd);
		return (1);
	}
	if (!cmd->split[2])
	{
		ft_put_one_alias(cmd);
		return (1);
	}
	return (0);
}

static int			sh_setalias(t_cmd *cmd, char *str)
{
	t_list	*alias;

	if ((alias = ft_find_list(cmd->alias, cmd->split[1])))
	{
		free(alias->valeure);
		alias->valeure = str;
	}
	else
	{
		cmd->alias = ft_add_arg(cmd->split[1], str, cmd->alias);
		free(str);
	}
	return (0);
}

int					sh_alias(t_cmd *cmd)
{
	t_list	*alias;
	char	*tmp;
	char	*result;
	int		index;

	index = 2;
	tmp = NULL;
	result = NULL;
	if (alias_isvalid(cmd))
		return (0);
	alias = cmd->alias;
	while (cmd->split[index])
	{
		tmp = ft_strdup(result);
		if (result)
		{
			free(result);
			result = str_join_chr(tmp, cmd->split[index], ' ');
		}
		else
			result = ft_strdup(cmd->split[index]);
		free(tmp);
		index++;
	}
	return (sh_setalias(cmd, result));
}
