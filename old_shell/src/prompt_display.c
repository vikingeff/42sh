/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:35:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/04 17:15:40 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

static void		set_tild(int *home, char **pwd, t_dir *dir);
static void		put_path(int *home, int *i, t_dir *dir, char **pwd);

/*
** display the user path from his home to his current directory
*/

void			prompt_display(t_dir *dir)
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
		put_path(&home, &i, dir, pwd);
	ft_putstr("\033[1;34m/$>\033[037m");
	array2d_free(pwd);
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

static void		put_path(int *home, int *i, t_dir *dir, char **pwd)
{
	if (*home == 1)
		{
			ft_putstr("\033[1;34m/");
			ft_putstr(pwd[*i]);
		}
		if (ft_strcmp(pwd[*i], dir->user) == 0)
		{
			ft_putstr("\033[1;34m~");
			*home = 1;
		}
}