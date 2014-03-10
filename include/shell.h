/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:44:57 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/28 18:02:40 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <termios.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <glob.h>
# include <sys/socket.h>

# define ESC key[0] == 27 || key[0] == 3
# define UP key[0] == 4283163
# define DOWN key[0] == 4348699
# define LEFT key[0] == 4479771
# define RIGHT key[0] == 4414235
# define DEL key[0] == 2117294875
# define BCKSPC key[0] == 127
# define ENTER key[0] == 10 || key[0] == 4
# define SPACE key[0] == 32
# define TAB key[0] == 9
# define JUMP_FIRST key[0] == 4741915 || key[0] == 1
# define JUMP_LAST key[0] == 4610843 || key[0] == 5
# define JUMP_WORD_NEXT key[0] == 73883020516123
# define JUMP_WORD_PREV key[0] == 74982532143899
# define JUMP_UP key[0] == 71683997260571
# define JUMP_DOWN key[0] == 72783508888347


extern pid_t		process_id;

typedef struct s_env	t_env;
typedef struct s_dir	t_dir;
typedef struct s_var	t_var;
typedef struct s_cmd	t_cmd;
typedef struct s_bar	t_bar;

/*
** term
*/

typedef struct termios	t_term;
typedef struct s_char 	t_char;
typedef struct s_cur	t_cur;
typedef struct s_comp	t_comp;

struct		s_comp
{
	int		status;
	int		begin;
	char	*tmp;
	char	*word;
	char	*end;
	char	*final;
	int		f_len;
	int 	i;
};

struct		s_cur
{
	int		x;
	int		y;
	int		line_x;
	int		nb_line;
	int		term_len;
	int		prompt_len;
};

struct		s_char
{
	char	c;
	int		mirror;
	int		nl;
	t_char	*next;
	t_char	*prev;
};

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

typedef struct		s_hist
{
	char			*data;
	char			*time;
	int				index;
	int				size;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

struct		s_cmd
{
	char	*raw;
	char	**split;
	char	**env;
	char	**paths;
	t_list	*alias;
	t_hist	*hist;
	t_hist	*nav;
	int		ret;
	int		cmd_end;
	int		len;
	int		exit;
	int		comp;
	char	*actual;
	int		s_cursor;
	int		sig;
	int		fdsave;
	char	*save_cur;
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
	char			**raw;
	int				nb;
	t_var			*var;
	t_term			*term;
	unsigned long	canon_save;
	long			key[1];
	int				term_len;
	char			*prompt;
	int				prompt_len;
};

int		error(int err, char *detail);
int		term_error(int err);
int		shell_ini(t_cmd *cmd, t_dir *dir, t_env *env, char **environ);
t_var	*env_array_to_list(t_env *env);
char	**env_list_to_array(t_var *var, int size);
int		env_list_add(t_var **list, t_var **start);
char	*str_join_chr(char const *s1, char const *s2, char c);
void	array2d_free(char **array);
char	**array2d_copy(char **src);
char	*env_get_value(char *name, t_env *env);
char	*prompt_display(t_dir *dir);
int		get_next_line(const int fd, char **line);
int		ft_tablen(char **table);
char	**copy_table_i(char **table, int index);
void	*ft_remember(t_cmd *cmd, t_dir *dir, t_env *env, int flag);
int		wait_process(pid_t pid);

void	sh_exit(t_cmd *cmd);
int		sh_env(t_cmd *cmd, t_env *env, t_dir *dir);
int		sh_unsetenv(t_cmd *cmd, t_env *env);
void	init_copy_env(t_env *c_env, t_cmd *c_cmd, t_dir *c_dir);
int		ft_put_env(t_cmd *c_cmd, t_env *c_env, t_dir *dir);
void	ft_free_c_env(t_env *c_env, t_cmd *c_cmd, t_dir *dir);
int		sh_setenv(t_cmd *cmd, t_env *env);
int		sh_cd(t_cmd *cmd, t_env *env, t_dir *dir);
char	*get_path(char *newpath, char **split);
char	*newpath_write(char *curpath, char *modif);
char	*get_newpath(char **modif, t_dir *dir, char *curpath);
int		sh_echo(t_cmd *cmd, t_env *env, t_dir *dir);
int		sh_alias(t_cmd *cmd);
int		sh_unalias(t_cmd *cmd);

void	command_get(t_env *env, t_cmd *cmd);
int		command_parse(t_cmd *cmd, t_env *env, t_dir *dir);
int		command_get_env(t_cmd *cmd, t_env *env, t_dir *dir);
int		command_shell(t_cmd *cmd, t_env *env, t_dir *dir);
int		command_execute(t_cmd *cmd, t_env *env, t_dir *dir);
int		command_execute_no_wait(t_cmd *cmd, t_env *env, t_dir *dir);
int		command_execute_simple(t_list *arg,
	t_cmd *cmd, t_env *env, t_dir *dir);
int		ft_main_loop(t_cmd *cmd, t_dir *dir, t_env *env, t_list **arg);
/*
** terminal
*/

int		term_canonical_mode(t_env *env, int mode);
int		term_ini(t_env *env);
int		term_put(char *opt_id);
int		term_set_attr(t_term *term);
void	term_edit_set(t_env *env);
void	term_std_set(t_env *env);

/*
** line edition
*/

int		edit_key(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);
t_char	*edit_char_add(t_char *list, long chr, t_cur *cursor, t_cmd *cmd);
t_char	*edit_char_del(t_char *list, t_cmd *cmd, t_cur *cursor);
void	edit_erase_display(t_cur *cursor);
void	edit_line_display(t_char *list, t_cur *cursor, t_cmd *cmd, t_env *env);
char	*edit_list_to_str(t_char *list, t_cmd *cmd, t_cur *cursor);

void	k_esc(t_cmd *cmd);
void	k_left(t_cur *cursor, t_char **list);
void	k_right(t_cmd *cmd, t_cur *cursor, t_char **list);
void	k_bckspc(t_cmd *cmd, t_cur *cursor, t_char **list);
void	k_enter(t_cmd *cmd);
void	k_del(t_cmd *cmd, t_cur *cursor, t_char **list);
void	k_jump_first(t_cur *cursor, t_char **list);
void	k_jump_last(t_cmd *cmd, t_cur *cursor, t_char **list);
void	k_jump_word_prev(t_cur *cursor, t_char **list);
void	k_jump_word_next(t_cmd *cmd, t_cur *cursor, t_char **list);
void	k_jump_up(t_char **list, t_cur *cursor, t_cmd *cmd);
void	k_jump_down(t_char **list, t_cur *cursor, t_cmd *cmd);

/*
** signal
*/

void	ft_signal(void);

/*
** utility
*/

char	**ft_strsplit_all(char const *s);
char	**ft_tab_dup(char **table);

/*
** sh2
*/

t_var	*env_lst_copy(t_env *env);
t_list	*ft_add_arg(char *str, char *type, t_list *list);
t_list	*ft_parser(char *str);
int		ft_parse_arg(t_list *arg);
t_list	*ft_parser_direct(t_list *arg);
t_list	*ft_lstadd_first(t_list *lst, t_list *new);
char	*ft_modify_arg(t_list *arg, int index, int mode);
t_list	*ft_lstnew(char *content);
int		ft_launcher(t_list **arg, t_cmd *cmd, t_env *env, t_dir *dir);
int		ft_get_fd(t_list *dir);
void	ft_dup2(int newfd, int oldfd);
int		ft_execute(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);
int		ft_execute_no_wait(t_list *arg, t_cmd *cmd, t_env *env, t_dir *dir);
void	ft_close(int fd[2]);

/*
** free arg
*/

void	ft_free_arg(t_list **arg);
t_list	*ft_free_one(t_list *list);
void	delete_temp_free(t_list **arg, t_cmd *cmd, t_env *env, t_dir *dir);

/*
** pipe
*/

int		ft_count_pipe(t_list *arg);
t_list	*ft_pipe(t_list *arg, t_dir *dir, t_env *env, t_cmd *cmd);
void	ft_close_pipe(int *fdpipe, int pipenb);

/*
** history
*/

t_hist	*create_list(void);
void	add_ahead(t_hist *elem, char *data, char *time, int index);
t_hist	*list_filling(t_hist *hist, char *av);
int		print_hist(t_cmd *cmd);
char	*time_padding(char *src);
char	*ft_strjoin_free(char *res, char *str);
char	*ft_strjoin_double_free(char *res, char *str);
void	del_hist(t_cmd *cmd);
int		hist_is_valid(t_cmd *cmd);
void	hist_navig(long key[], t_cmd *cmd, t_cur *cursor, t_char **list);
int		hist_chr(t_cmd *cmd, t_dir *dir, t_env *env);
int		filling_checking(t_cmd *cmd);
void	ft_lauch_history(t_cmd *cmd, t_dir *dir, t_env *env, char *newcmd);

/*
** BONUS : inib, local var, backquote, alias
*/

int		ft_inib_starter(t_cmd *cmd);
void	ft_get_var(t_cmd *cmd, t_env *env);
void	ft_open_close(void);
void	execute_backquote(t_cmd *cmd, t_env *env, t_dir *dir);
void	ft_delete_char(t_cmd *cmd, int index);
void	sh_cmd(void);
void	ft_get_alias(t_cmd *cmd);
t_list	*ft_find_list(t_list *list, char *str);
int		ft_special_char(char c);
void	completion(t_cmd *cmd, t_cur *cursor, t_char **list, int flag);
void	reset_comp(t_cmd *cmd);
char	*fill_completion(t_cmd *cmd, char *str, int status, int flag);
int		ft_find_status(char *str, int begin);
void	ft_globing(t_cmd *cmd);

#endif /*SHELL_H*/
