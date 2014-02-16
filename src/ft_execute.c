/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:58:45 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/16 14:55:13 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_execute(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;

	if (cmd->raw)
		free(cmd->raw);
	cmd->raw = ft_strdup(arg->mot);
	if (command_parse(cmd, env, dir))
	{
		error(4, "`");
		return (256);
	}
	if (cmd->split[0])
		if ((ret = command_execute(cmd, env, dir)) == -1)
			return (ret);
	return (ret);
}

int		ft_execute_no_wait(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;

	if (cmd->raw)
		free(cmd->raw);
	cmd->raw = ft_strdup(arg->mot);
	if (command_parse(cmd, env, dir))
	{
		error(4, "`");
		return (256);
	}
	if (cmd->split[0])
		if ((ret = command_execute_no_wait(cmd, env, dir)) == -1)
			return (ret);
	return (ret);
}

t_list	*ft_avoid_pipe(t_list *arg)
{
	if (!arg || ft_strcmp(arg->valeure, "|"))
		return (arg);
	while (arg && ft_strcmp(arg->valeure, "|"))
		arg = arg->next;
	arg = arg->next;
	return (arg);
}


int		ft_launcher(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;

	ret = -1;
	while (arg)
	{
		if (arg->prev && (ft_strcmp(arg->prev->valeure, "&&") == 0
			|| ft_strcmp(arg->prev->valeure, "||") == 0) && ret)
		{
			arg = arg->next;
			arg = ft_avoid_pipe(arg);
			continue ;
		}
		if (ft_strcmp(arg->valeure, "|") == 0)
		{
			arg->pipenb = ft_count_pipe(arg);
			arg = ft_pipe(arg, dir, env, cmd);
			ret = 0;
		}
		else
		{
			ret = command_execute_simple(arg, cmd, env, dir);
			arg = arg->next;
		}
	}
	return (ret);
}
