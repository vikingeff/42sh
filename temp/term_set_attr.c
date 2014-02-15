/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_set_attr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:44:48 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 19:57:23 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*apply the new set of attributs in the terminal*/
int		term_set_attr(t_term *term)
{
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (error(3));
	return (0);
}