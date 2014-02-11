/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:44:57 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 14:05:03 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

					#include <stdio.h> // TEMP
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_env	t_env;
typedef struct s_dir	t_dir;
typedef struct s_var	t_var;
typedef struct s_cmd	t_cmd;

struct		s_cmd
{
	char	*raw;
	char	**split;
	char	**env;
	char	**paths;
	int		exit;
};

struct		s_dir
{
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	*user;
	char	*current;
};

struct		s_var
{
	char	*name;
	char	*value;
	t_var	*next;
};

struct		s_env
{
	char	**raw;
	int		nb;
	t_var	*var;
};

int			error(int err, char *detail);
int			shell_ini(t_cmd *cmd, t_dir *dir, t_env *env);
t_var		*env_array_to_list(t_env *env);
char		**env_list_to_array(t_var *var, int size);
int			env_list_add(t_var **list, t_var **start);
char		*str_join_chr(char const *s1, char const *s2, char c);
void		env_list_create(t_cmd *cmd, t_env *env);
void		array2d_free(char **array);
char		**array2d_copy(char **src);
char		*env_get_value(char *name, t_env *env);
void		prompt_display(t_dir *dir);
int			get_next_line(const int fd, char **line);

void		sh_exit(t_cmd *cmd);
int			sh_env(t_cmd *cmd, t_env *env);
int			sh_unsetenv(t_cmd *cmd, t_env *env);
int			sh_setenv(t_cmd *cmd, t_env *env);
void		sh_cd(t_cmd *cmd, t_env *env, t_dir *dir);

int			command_get(t_cmd *cmd);
int			command_parse(t_cmd *cmd);
int			command_get_env(t_cmd *cmd, t_env *env);
int			command_shell(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_execute(t_cmd *cmd, t_env *env, t_dir *dir);

#endif /*LEM_H*/
