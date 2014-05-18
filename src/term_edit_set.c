/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_edit_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 00:47:42 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:13:44 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	term_edit_set(t_env *env)
{
	env->term_len = tgetnum("co");
	term_put("vi");
	term_put("im");
	term_canonical_mode(env, 0);
}
