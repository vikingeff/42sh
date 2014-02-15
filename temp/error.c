/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:38:48 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 18:41:14 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		term_error(int err)
{
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
		ft_putendl_fd("tputs() failed: can't set the new cup", 2);
	else if (err == 5)
		ft_putendl_fd("tputs() failed: can't close correctly the cup", 2);
}

static void		main_error(int err)
{
	if (err == 10)
		ft_putendl_fd("Usage : arguments expected", 2);
	else if (err == 11)
		ft_putendl_fd("set_list: malloc() failed", 2);
	else if (err == 12)
		ft_putendl_fd("list_add: malloc() failed", 2);
	else if (err == 13)
		ft_putendl_fd("list_add: open() failed: can't open /dev/tty", 2);
}

/*display errors: 0-9: termios errors | 10-19:  misc|*/
int				error(int err)
{
	if (err < 10)
		term_error(err);
	if (err >= 10 && err < 20)
		main_error(err);
	return (1);
}