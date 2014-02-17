/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:44:57 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/17 14:19:37 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

					# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

extern pid_t		process_id;

typedef struct s_env	t_env;
typedef struct s_dir	t_dir;
typedef struct s_var	t_var;
typedef struct s_cmd	t_cmd;
typedef struct s_bar	t_bar;

typedef struct		s_list
{
	char			*mot;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*dir;
	char			*valeure;
	int				fd;
	int				error;
	int				pipenb;
}					t_list;

struct		s_cmd
{
	char	*raw;
	char	**split;
	char	**env;
	char	**paths;
	char	**alias;
	int		exit;
};

struct		s_dir
{
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	*user;
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
void		array2d_free(char **array);
char		**array2d_copy(char **src);
char		*env_get_value(char *name, t_env *env);
void		prompt_display(t_dir *dir);
int			get_next_line(const int fd, char **line);
int			ft_tablen(char **tab);

void		sh_exit(t_cmd *cmd);
int			sh_env(t_cmd *cmd, t_env *env, t_dir *dir);
int			sh_unsetenv(t_cmd *cmd, t_env *env);
void		init_copy_env(t_env *c_env, t_cmd *c_cmd, t_dir *c_dir);
int			ft_put_env(t_cmd *c_cmd, t_env *c_env, t_dir *dir);
void		ft_free_c_env(t_env *c_env, t_cmd *c_cmd, t_dir *dir);
int			sh_setenv(t_cmd *cmd, t_env *env);
int			sh_cd(t_cmd *cmd, t_env *env, t_dir *dir);
char		*get_path(char *newpath, char **split);
char		*newpath_write(char *curpath, char *modif);
char		*get_newpath(char **modif, t_dir *dir, char *curpath);
int			sh_echo(t_cmd *cmd, t_env *env, t_dir *dir);

int			command_get(t_cmd *cmd);
int			command_parse(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_get_env(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_shell(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_execute(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_execute_no_wait(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_execute_simple(t_list *arg,
	t_cmd *cmd, t_env *env, t_dir *dir);

/*
** signal
*/

void		ft_signal(void);

/*
** utility
*/

char		**ft_strsplit_all(char const *s);
char		**ft_tab_dup(char **tab);

/*
** sh2
*/

t_var		*env_lst_copy(t_env *env);
t_list		*ft_add_arg(char *str, char *type, t_list *list);
t_list		*ft_parser(char *str);
t_list		*ft_parser_direct(t_list *arg);
t_list		*ft_lstadd_first(t_list *lst, t_list *new);
char		*ft_modify_arg(t_list *arg, int index, int mode);
t_list		*ft_lstnew(char *content);
int			ft_launcher(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);
int			ft_get_fd(t_list *dir);
void		ft_dup2(int newfd, int oldfd);
int			ft_execute(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);
int			ft_execute_no_wait(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);
void		ft_close(int fd[2]);

/*
** free arg
*/

void		ft_free_arg(t_list *arg);
t_list		*ft_free_one(t_list *list);
void		delete_temp_free(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);

/*
** pipe
*/

int			ft_count_pipe(t_list *arg);
t_list		*ft_pipe(t_list *arg, t_dir *dir, t_env *env, t_cmd *cmd);
void		ft_close_pipe(int *fdpipe, int pipenb);

/*
** BONUS : inib, local var, backquote
*/

int			ft_inib_starter(t_cmd *cmd);
void		ft_get_var(t_cmd *cmd, t_env *env);
void		ft_open_close(void);
void		execute_backquote(t_cmd *cmd, t_env *env, t_dir *dir);
void		ft_delete_char(t_cmd *cmd, int index);
void		sh_cmd();

#endif /*LEM_H*/
