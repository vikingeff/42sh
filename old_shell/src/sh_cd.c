/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:04:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 14:08:53 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

static void		change_dir(char *n_dir, t_dir *dir, t_cmd *cmd, t_env *env);
static char		*newpath_write(char *curpath, char *modif);

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
	int			i;

	i = -1;
	if (!cmd->split[1])
		change_dir(dir->home, dir, cmd, env);
	else if (cmd->split[1][0] == '~')
		change_dir(dir->home, dir, cmd, env);
	else if (cmd->split[1][0] == '-')
		change_dir(env_get_value("OLDPWD", env), dir, cmd, env);
	else if (cmd->split[1][0] == '/')
		change_dir(cmd->split[1], dir, cmd, env);
	else
	{
		modif = ft_strsplit(cmd->split[1], '/');
		while (modif[++i])
		{
			if ((curpath = newpath_write(dir->pwd, modif[i])))
				change_dir(curpath, dir, cmd, env);
			else
				break ;
		}
	}
}

static void		change_dir(char *n_dir, t_dir *dir, t_cmd *cmd, t_env *env)
{
	cmd->split[0] = ft_strdup("setenv");
	cmd->split[1] = ft_strdup("OLDPWD");
	cmd->split[2] = ft_strdup(dir->pwd);


	dir->oldpwd = ft_strdup(dir->pwd);
	printf("TEST 2: %s\n", cmd->split[2]);
	sh_setenv(cmd, env);


	cmd->split[0] = ft_strdup("setenv");
	cmd->split[1] = ft_strdup("PWD");
	cmd->split[2] = (n_dir[0] == '-') ? ft_strdup(dir->oldpwd) : n_dir;
	dir->pwd = (n_dir[0] == '-') ? dir->oldpwd : n_dir;
	sh_setenv(cmd, env);
	

	if (n_dir[0] == '-')
		chdir(env_get_value("PWD", env));
	else
		chdir(n_dir);
}

static char		*newpath_write(char *curpath, char *modif)
{
	char		*newpath;
	char		**split;
	int			i;

	i = 0;
	newpath = "";
	if (modif[0] != '.')
		newpath = str_join_chr(curpath, modif, '/');
	else if (modif[1] == '.')
	{
		split = ft_strsplit(curpath, '/');
		while (split[i + 1])
			newpath = str_join_chr(newpath, split[i++], '/');
	}
	else
		newpath = curpath;
	if (access(newpath, F_OK))
	{
		error(33, modif);
		return (NULL);
	}
	return (newpath);
}