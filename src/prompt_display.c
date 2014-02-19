/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:35:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 14:34:14 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

static void		set_tild(int *home, char **pwd, t_dir *dir);
static char		*put_path(int *home, int *i, t_dir *dir, char **pwd);
static char		*put_prompt(t_dir *dir, char *str, char *tmp, char *tmp2);

/*
** display the user path from his home to his current directory
*/

char			*prompt_display(t_dir *dir)
{
	static t_dir	*dir_save;
	char			*str;
	char			*tmp;
	char			*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	str = NULL;
	if (dir == NULL)
		return (put_prompt(dir_save, str, tmp, tmp2));
	dir_save = dir;
	return (put_prompt(dir_save, str, tmp, tmp2));
}

static char		*put_prompt(t_dir *dir, char *str, char *tmp, char *tmp2)
{
	char		**pwd;
	int			i;
	int			home;
	char		*curr_path;
	char		buff[200];

	i = -1;
	curr_path = getcwd(buff, 200);
	pwd = ft_strsplit(curr_path, '/');
	set_tild(&home, pwd, dir);
	while (pwd[++i])
	{
		tmp = ft_strdup(str);
		free(str);
		tmp2 = put_path(&home, &i, dir, pwd);
		str = ft_strjoin(tmp, tmp2);
		free(tmp2);
		free(tmp);
	}
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, "/$>");
	free(tmp);
	array2d_free(pwd);
	return (str);
}

static void		set_tild(int *home, char **pwd, t_dir *dir)
{
	int			i;

	i = 0;
	*home = 1;
	while (pwd[i])
	{
		if (ft_strcmp(pwd[i], dir->user) == 0)
			*home = 0;
		i++;
	}
}

static char		*put_path(int *home, int *i, t_dir *dir, char **pwd)
{
	char	*str;

	if (*home == 1)
			str = ft_strjoin("/", pwd[*i]);
	else if (ft_strcmp(pwd[*i], dir->user) == 0)
	{
		str = ft_strdup("~");
		*home = 1;
	}
	return (str);
}