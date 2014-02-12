/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:04:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 18:22:52 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

static void		change_dir(char *n_dir, t_dir *dir, t_cmd *cmd, t_env *env);
static char		*newpath_write(char *curpath, char *modif);
static char		*get_newpath(char **modif, t_dir *dir, char *curpath);
static char		*get_path(char *newpath, char **split);
/*
** change the current directory according to the given argument path and
** change the env variables PWD and OLDPWD according to it.
** ----- OPTIONS -----
** if no path or '~' : the new dir will be the home path.
** if '-' : the new dir will be the last known path.
** if starts with '/' : the new dir will be an absolute path.
** if starts with '..' : the new dir will be step back on the path branch
*/

void			sh_cd(t_cmd *cmd, t_env *env, t_dir *dir)
{
	char		*curpath;
	char		**modif;

	if (!cmd->split[1])
		change_dir(dir->home, dir, cmd, env);
	else if (cmd->split[1][0] == '~')
		change_dir(dir->home, dir, cmd, env);
	else if (cmd->split[1][0] == '-')
	{
		change_dir(env_get_value("OLDPWD", env), dir, cmd, env);
		ft_putendl(env_get_value("OLDPWD", env));
	}
	else if (cmd->split[1][0] == '/')
		change_dir(cmd->split[1], dir, cmd, env);
	else
	{
		modif = ft_strsplit(cmd->split[1], '/');
		curpath = get_newpath(modif, dir, curpath);
		change_dir(curpath, dir, cmd, env);
	}
}

static char			*get_newpath(char **modif, t_dir *dir, char *curpath)
{
	char		*tmp;
	int			i;

	curpath = ft_strdup(dir->pwd);
	i = -1;
	tmp = NULL;
	while (modif[++i])
	{
		if (curpath)
		{
			tmp = ft_strdup(curpath);
			free(curpath);
		}
		curpath = newpath_write(tmp, modif[i]);
		if (tmp)
			free(tmp);
	}
	return (curpath);
}

static void		change_dir(char *n_dir, t_dir *dir, t_cmd *cmd, t_env *env)
{
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

static char		*newpath_write(char *curpath, char *modif)
{
	char		*newpath;
	char		**split;

	newpath = NULL;
	if (modif[0] != '.')
		newpath = str_join_chr(curpath, modif, '/');
	else if (modif[1] == '.')
	{
		split = ft_strsplit(curpath, '/');
		newpath = get_path(newpath, split);
		array2d_free(split);
	}
	else
		newpath = curpath;
	if (access(newpath, F_OK))
	{
		error(33, newpath);
		return (NULL);
	}
	return (newpath);
}

static char		*get_path(char *newpath, char **split)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (split[i + 1])
	{
		if (newpath)
		{
			tmp = ft_strdup(newpath);
			free(newpath);
		}
		newpath = str_join_chr(tmp, split[i], '/');
		if (tmp)
			free(tmp);
		i++;
	}
	return (newpath);
}