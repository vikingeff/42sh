/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:47:13 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 13:45:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				puts_write(int c)
{
	write(1, &c, 1);
	return (1);
}

int				term_put(char *opt_id)
{
	if (tputs(tgetstr(opt_id, NULL), 1, puts_write) == ERR)
		return (-1);
	return (0);
}
