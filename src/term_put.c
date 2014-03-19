/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:47:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/28 17:06:11 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				puts_write(int c);

/*
**	apply the termcap id argument
*/

int				term_put(char *opt_id)
{
	if (tputs(tgetstr(opt_id, NULL), 1, puts_write) == ERR)
		return (-1);
	return (0);
}

int				puts_write(int c)
{
	write(1, &c, 1);
	return (1);
}