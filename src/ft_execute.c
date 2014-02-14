/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:58:45 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/14 16:20:11 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_execute(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;

	if (cmd->raw)
		free(cmd->raw);
	cmd->raw = ft_strdup(arg->mot);	
	command_parse(cmd, env);
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
	command_parse(cmd, env);
	if (cmd->split[0])
		if ((ret = command_execute_no_wait(cmd, env, dir)) == -1)
			return (ret);
	return (ret);
}

static int		*ft_init_fd(t_list *arg)
{
	int			*fd;

	fd = (int *)malloc(sizeof(int) * 2);
	fd[0] = 0;
	fd[1] = 1;
	while (arg->dir)
	{
		if (ft_strcmp(arg->dir->mot, ">>") == 0
			|| ft_strcmp(arg->dir->mot, ">") == 0)
			fd[1] = ft_get_fd(arg->dir);
		if (ft_strcmp(arg->dir->mot, "<<") == 0
			|| ft_strcmp(arg->dir->mot, "<") == 0)
			fd[0] = ft_get_fd(arg->dir);
		arg->dir = arg->dir->next;
	}
	ft_dup2(fd[0], 0);
	ft_dup2(fd[1], 1);
	return (fd);
}

void	ft_reverse_fd(int *fd)
{
	ft_dup2(fd[0], 0);
	ft_dup2(fd[1], 1);
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

int		ft_launcher (t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	ret;
	int *fd;
	int save[2];

	ret = -1;
	save[0] = dup(0);
	save[1] = dup(1);
	while (arg)
	{
		if (arg->prev && ft_strcmp(arg->prev->valeure, "&&") == 0 && ret)
		{
			arg = arg->next;
			arg = ft_avoid_pipe(arg);
			continue ;
		}
		if (arg->prev && ft_strcmp(arg->prev->valeure, "||") == 0 && ret == 0)
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
			fd = ft_init_fd(arg);
			ret = ft_execute(arg, cmd, env, dir);
			ft_close(fd);
			ft_reverse_fd(save);
			free(fd);
			arg = arg->next;
		}
	}
	return (ret);
}
