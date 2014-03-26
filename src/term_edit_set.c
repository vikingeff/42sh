/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_edit_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 00:47:42 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 13:45:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	term_edit_set(t_env *env)
{
	env->term_len = tgetnum("co");
	term_put("vi");
	term_put("im");
	term_canonical_mode(env, 0);
}
