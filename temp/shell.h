/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:32:14 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:08:43 by cobrecht         ###   ########.fr       */
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
# define DEL key[0] == 126
# define BCKSPC key[0] == 127
# define ENTER key[0] == 10
# define SPACE key[0] == 32

typedef struct termios t_term;
typedef struct s_char t_char;

struct		s_char
{
	char	c;
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

struct		s_env
{
	t_term	*term;
	int		key[1];
};

int		canonical_mode(t_term *term, int val);
int		term_ini(t_env *env);
int		term_put(char *opt_id);
int		term_set_attr(t_term *term);
int		command_get(t_env *env, t_cmd *cmd);
void	term_close(void);
t_char	*char_add(t_char *list, int chr, int *cursor_pos, t_cmd *cmd);
t_char	*char_del(t_char *list, t_cmd *cmd, int *cursor_pos);

void	k_esc(t_cmd *cmd);
void	k_left(int *cursor_pos, t_char **list);
void	k_right(t_cmd *cmd, int *cursor_pos, t_char **list);
void	k_bckspc(t_cmd *cmd, int *cursor_pos, t_char **list);
void	k_enter(t_cmd *cmd);

# endif 