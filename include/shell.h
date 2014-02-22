/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:44:57 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 11:13:01 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

					#include <stdio.h> // TEMP
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <termcap.h>
# include <termios.h>
# include "../libft/libft.h"
# define UP (key[0] == 27 && key[1] == 91 && key[2] == 65)
# define DOWN (key[0] == 27 && key[1] == 91 && key[2] == 66)
extern pid_t		process_id;

typedef struct		s_hist
{
	char			*data;
	char			*time;
	int				index;
	int				size;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

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
}					t_list;

struct		s_cmd
{
	char	*raw;
	char	**split;
	char	**env;
	char	**paths;
	t_hist	*hist;
	int		exit;
};

struct		s_dir
{
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	*user;
	//char	*current;
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
int			sh_setenv(t_cmd *cmd, t_env *env);
void		sh_cd(t_cmd *cmd, t_env *env, t_dir *dir);

int			command_get(t_cmd *cmd);
int			command_parse(t_cmd *cmd);
int			command_get_env(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_shell(t_cmd *cmd, t_env *env, t_dir *dir);
int			command_execute(t_cmd *cmd, t_env *env, t_dir *dir);

/*
** signal
*/

void		*uf_get_instance(void);
char		**ft_strsplit_all(char const *s);

/*
** sh2
*/

t_list	*ft_add_arg(char *str, char *type, t_list *list);
t_list	*ft_parser_direct(t_list *arg);
t_list	*ft_lstadd_first(t_list *lst, t_list *new);
char	*ft_modify_arg(t_list *arg, int index, int mode);
t_list	*ft_lstnew(char *content);


/*PRINT*/
int			tputs_putchar(int c);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstr(const char *s);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putendl(const char *s);
void		ft_putnbr(int n);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);


/*LIST*/
t_hist		*create_list(void);
void		add_ahead(t_hist *elem, char *data, char *time, int index);
t_hist		*list_filling(t_hist *hist, char *av);
void		print_hist(t_cmd *cmd);
char		*time_padding(char *src);
char		*ft_strjoin_free(char *res, char *str);

#endif /*LEM_H*/
