/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_canonical_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:42:16 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:13:45 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

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
