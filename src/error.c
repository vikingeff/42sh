/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 13:53:09 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/21 19:25:05 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		usage(int err, char *detail);
static void		err_system(int err, char *detail);
static void		warning(int err, char *detail);
int				term_error(int err);

/*
** Display an error message with potential details.
** if ext option is set to 0 : return -1, else exit minishell.
*/

int				error(int err, char *detail)
{
	ft_putstr_fd("\033[033m", 2);
	if (err < 15)
		usage(err, detail);
	else if (err < 30)
		err_system(err, detail);
	else if (err < 45)
		warning(err, detail);
	ft_putendl_fd("\033[m", 2);
	return (-1);
}

/*
** error 0 - 15 : usage errors
*/

static void		usage(int err, char *detail)
{
	ft_putstr_fd("Usage : ", 2);
	if (err == 0)
		ft_putstr_fd("minishell expect no arguments", 2);
	else if (err == 1)
		ft_putstr_fd("unsetenv [variable]", 2);
	else if (err == 2)
		ft_putstr_fd("setenv [variable] [value]", 2);
	else if (err == 3)
	{
		ft_putstr_fd("env : illegal option --", 2);
		ft_putstr_fd(detail, 2);
		ft_putstr_fd("\nenv [-i] [name=value ...] [utility [argument ...]]", 2);
	}
	else if (err == 4)
	{
		ft_putstr_fd("Unmatched ", 2);
		ft_putstr_fd(detail, 2);
		ft_putstr_fd(".", 2);
	}
	else if (err == 5)
		ft_putstr_fd("Invalid null command.", 2);
	else if (err == 6)
		ft_putstr_fd("Missing name for redirect.", 2);
}

/*
** error 15 - 30 : system errors
*/

static void		err_system(int err, char *detail)
{
	ft_putstr_fd("System error : ", 2);
	if (err == 15)
	{
		ft_putstr_fd(detail, 2);
		ft_putstr_fd(" cannot allocated sufficent memory.", 2);
	}
	else if (err == 16)
	{
		ft_putstr_fd("failure on get_next_line(user's command)", 2);
	}
}

/*
** error 30 - 45 : warnings
*/

static void		warning(int err, char *detail)
{
	ft_putstr_fd("Minishell: ", 2);
	if (err == 30)
	{
		ft_putstr_fd("environnement variable cannot be found: ", 2);
		ft_putstr_fd(detail, 2);
	}
	else if (err == 31)
	{
		ft_putstr_fd("environnement variable not set: ", 2);
		ft_putstr_fd(detail, 2);
	}
	else if (err == 32)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(detail, 2);
	}
	else if (err == 33)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(detail, 2);
	}
}

/*
** term
*/

int		term_error(int err)
{
	ft_putstr_fd("\033[033m", 2);
	ft_putstr("Error termios: ");
	if (err == 0)
		ft_putendl_fd("getenv() failed: can't get TERM env name", 2);
	else if (err == 1)
		ft_putendl_fd("tgetent() failed: term database cannot be found", 2);
	else if (err == 2)
		ft_putendl_fd("tcgetattr() failed: can't set up termios struct", 2);
	else if (err == 3)
		ft_putendl_fd("tcsetattr() failed: can't apply new term attr", 2);
	else if (err == 4)
		ft_putendl_fd("Can't make a copy of termios", 2);
	ft_putstr_fd("\033[m", 2);
	return (-1);
}