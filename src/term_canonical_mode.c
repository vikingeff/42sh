/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_canonical_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:42:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 13:47:08 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
