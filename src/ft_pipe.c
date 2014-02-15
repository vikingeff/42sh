/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 19:03:38 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/15 17:50:05 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_create_pipe(int *fdpipe, int pipenb)
{
	int	index;

	index = 0;
	while (index < pipenb)
	{
		pipe(fdpipe + index * 2);
		index++;
	}
}

static int	ft_pipe1(int fd[2], t_list *arg, int *fdpipe, int count)
{
	if (ft_strcmp(arg->valeure, ";") != 0)
		ft_dup2(fdpipe[count + 1], 1);
	else
	{
		fd[1] = ft_get_fd(arg->dir);
		ft_dup2(fd[1], 1);
	}
	return (fd[1]);
}

static int	ft_pipe0(int fd[2], t_list *arg, int *fdpipe, int count)
{
	if (count != 0)
		ft_dup2(fdpipe[count - 2], 0);
	else
	{
		fd[0] = ft_get_fd(arg->dir);
		ft_dup2(fd[0], 0);
	}
	return (fd[0]);
}

static void	ft_wait_pipe(int pipenb)
{
	int	index;

	index = 0;
	while (index < (pipenb + 1))
	{
		wait(NULL);
		index++;
	}
}

t_list		*ft_pipe(t_list *arg, t_dir *dir, t_env *env, t_cmd *cmd)
{
	int		count;
	pid_t	pid;
	int		fdpipe[2 * arg->pipenb];
	int		fd[2] = {0, 1};
	int		pipenb;

	pipenb = arg->pipenb;
	count = 0;
	ft_create_pipe(fdpipe, arg->pipenb);
	while (count < pipenb * 2 + 2)
	{
		if ((pid = fork()) == 0)
		{
			fd[1] = ft_pipe1(fd, arg, fdpipe, count);
			fd[0] = ft_pipe0(fd, arg, fdpipe, count);
			ft_close_pipe(fdpipe, pipenb);
			ft_execute_no_wait(arg, cmd, env, dir);
		}
		arg = arg->next;
		count = count + 2;
	}
	ft_close_pipe(fdpipe, pipenb);
	ft_wait_pipe(pipenb);
	ft_close(fd);
	return (arg);
}
