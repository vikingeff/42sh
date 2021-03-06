/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_set_attr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:44:48 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:13:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		term_set_attr(t_term *term)
{
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (term_error(3));
	return (0);
}
