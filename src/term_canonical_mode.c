/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_canonical_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:42:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 00:32:36 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*turn on(1)/off(0) the terminal canonical mode*/
int		term_canonical_mode(t_env *env, int mode)
{
	if (mode == 0)
		env->term->c_lflag &= ~(ICANON | ECHO);
	else
		env->term->c_lflag = env->canon_save;
	if (term_set_attr(env->term))
		return (-1);
	return (0);
}