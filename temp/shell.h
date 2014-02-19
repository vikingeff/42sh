/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:32:14 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 09:26:13 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "libft/libft.h"

int		error(int err);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
char	*ft_strdup(const char *s1);
int		get_next_line(const int fd, char **line);

typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;









/* to add */

# include <termios.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>

# define ESC key[0] == 27
# define UP key[0] == 4283163
# define DOWN key[0] == 4348699
# define LEFT key[0] == 4479771
# define RIGHT key[0] == 4414235
# define DEL key[0] == 2117294875
# define BCKSPC key[0] == 127
# define ENTER key[0] == 10
# define SPACE key[0] == 32
# define JUMP_FIRST key[0] == 4741915 || key[0] == 1
# define JUMP_LAST key[0] == 4610843 || key[0] == 5
# define JUMP_WORD_NEXT key[0] == 73883020516123
# define JUMP_WORD_PREV key[0] == 74982532143899
# define JUMP_UP key[0] == 71683997260571
# define JUMP_DOWN key[0] == 72783508888347

typedef struct termios t_term;
typedef struct s_char t_char;
typedef struct s_cur	t_cur;

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

struct		s_cmd
{
	char	*raw;
	int		exit;
	int		cmd_end;
	int		len;
};

struct			s_env
{
	t_term		*term;
	long		key[1];
	int			term_len;
	char		*prompt;
	int			prompt_len;
};

int		command_get(t_env *env, t_cmd *cmd);		/*to check*/

/*
** terminal
*/

int		term_canonical_mode(t_term *term, int val);
int		term_ini(t_env *env);
int		term_put(char *opt_id);
int		term_set_attr(t_term *term);
void	term_close(t_env *env);

/*
** line edition
*/

t_char	*edit_char_add(t_char *list, long chr, t_cur *cursor, t_cmd *cmd);
t_char	*edit_char_del(t_char *list, t_cmd *cmd, t_cur *cursor);
void	edit_erase_display(t_cur *cursor);
void	edit_line_display(t_char *list, t_cur *cursor, t_cmd *cmd, t_env *env);

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

# endif 