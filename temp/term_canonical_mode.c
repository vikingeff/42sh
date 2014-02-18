/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_canonical_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:42:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/18 20:58:36 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*turn on(1)/off(0) the terminal canonical mode*/
int		term_canonical_mode(t_term *term, int val)
{
	if (val == 0)
		term->c_lflag &= ~(ICANON | ECHO);
	else
		term->c_lflag &= (ICANON | ECHO);
	if (term_set_attr(term))
		return (-1);
	return (0);
}