/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:04:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/15 18:25:22 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

/*
** change the current directory according to the given argument path and
** change the env variables PWD and OLDPWD according to it.
** ----- OPTIONS -----
** if no path or '~' : the new dir will be the home path.
** if '-' : the new dir will be the last known path.
** if starts with '/' : the new dir will be an absolute path.
** if starts with '..' : the new dir will be step back on the path branch
*/

static void		change_dir(char *n_dir, t_dir *dir, t_cmd *cmd, t_env *env)
{
	if (!n_dir)
		return ;
	array2d_free(cmd->split);
	cmd->split = ft_strsplit_all("setenv OLDPWD random");
	free(cmd->split[2]);
	cmd->split[2] = ft_strdup(dir->pwd);
	free(dir->oldpwd);
	dir->oldpwd = ft_strdup(dir->pwd);
	sh_setenv(cmd, env);
	array2d_free(cmd->split);
	cmd->split = ft_strsplit_all("setenv PWD random");
	free(cmd->split[2]);
	cmd->split[2] = ft_strdup(n_dir);
	free(dir->pwd);
	dir->pwd = ft_strdup(n_dir);
	sh_setenv(cmd, env);
	chdir(n_dir);
}

static int		sh_cd_home(t_cmd *cmd, t_env *env, t_dir *dir)
{
	if (access(dir->home, F_OK) == 0)
		change_dir(dir->home, dir, cmd, env);
	else
	{
		error(33, dir->home);
		return (256);
	}
	return (0);
}

static int		sh_cd_oldpwd(t_cmd *cmd, t_env *env, t_dir *dir)
{
	if (access(dir->oldpwd, F_OK) == 0)
	{
		change_dir(dir->oldpwd, dir, cmd, env);
		ft_putendl(dir->oldpwd);
	}
	else
	{
		error(33, dir->oldpwd);
		return (256);
	}
	return (0);
}

static int		sh_cd_absolute(t_cmd *cmd, t_env *env, t_dir *dir)
{
	char		*curpath;

	curpath = ft_strdup(cmd->split[1]);
	if (ft_strcmp(curpath, "/") == 0 || access(curpath, F_OK) == 0)
	{
		change_dir(curpath, dir, cmd, env);
		free(curpath);
	}
	else
	{
		error(33, curpath);
		free(curpath);
		return (256);
	}
	return (0);
}

int				sh_cd(t_cmd *cmd, t_env *env, t_dir *dir)
{
	char		*curpath;
	char		**modif;

	if (!cmd->split[1] || cmd->split[1][0] == '~')
		return (sh_cd_home(cmd, env, dir));
	else if (cmd->split[1][0] == '-')
		return (sh_cd_oldpwd(cmd, env, dir));
	else if (cmd->split[1][0] == '/')
		return (sh_cd_absolute(cmd, env, dir));
	else
	{
		modif = ft_strsplit(cmd->split[1], '/');
		if ((curpath = get_newpath(modif, dir, curpath)) == NULL)
		{
			error(33, curpath);
			free(curpath);
			return (256);
		}
		change_dir(curpath, dir, cmd, env);
		if (curpath)
			free(curpath);
		array2d_free(modif);
	}
	return (0);
}
