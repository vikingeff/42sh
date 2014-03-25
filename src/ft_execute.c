/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:58:45 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/28 17:28:50 by cobrecht         ###   ########.fr       */
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
		cmd->ret = 1;
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
		cmd->ret = 1;
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

void	if_pipe(t_list **arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	(*arg)->pipenb = ft_count_pipe(*arg);
	*arg = ft_pipe(*arg, dir, env, cmd);
}

int		ft_launcher(t_list **arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	t_list	*save;

	save = *arg;
	while (*arg)
	{
		if ((*arg)->prev
			&& ((ft_strcmp((*arg)->prev->valeure, "&&") == 0 && cmd->ret)
			|| (ft_strcmp((*arg)->prev->valeure, "||") == 0 && !cmd->ret)))
		{
			*arg = (*arg)->next;
			*arg = ft_avoid_pipe(*arg);
			continue ;
		}
		if (ft_strcmp((*arg)->valeure, "|") == 0)
			if_pipe(arg, cmd, env, dir);
		else
		{
			command_execute_simple(*arg, cmd, env, dir);
			*arg = (*arg)->next;
		}
	}
	*arg = save;
	return (0);
}
