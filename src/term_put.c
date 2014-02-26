/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:47:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/15 12:58:27 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				puts_write(int c);

/*	apply the termcap id argument:
** http://perkamon.alioth.debian.org/online/man5/termcap.5.php.fr */
int				term_put(char *opt_id)
{
	if (tputs(tgetstr(opt_id, NULL), 1, puts_write) == ERR)
		return (-1);
	return (0);
}

/* function needed by tputs() */
int				puts_write(int c)
{
	write(1, &c, 1);
	return (1);
}