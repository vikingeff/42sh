/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:37:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 14:58:47 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		term_ini(t_env *env)
{
	char	*n_term;

	if ((n_term = env_get_value("TERM", env)) == NULL)
		return (term_error(0));
	if (tgetent(NULL, n_term) == -1)
		return (term_error(1));
	if (tcgetattr(0, env->term) == -1)
		return (term_error(2));
	env->term->c_cc[VMIN] = 1;
	env->term->c_cc[VTIME] = 0;
	if (term_canonical_mode(env->term, 0))
		return (-1);
	env->term_len = tgetnum("co");
	term_put("vi");
	term_put("im");
	return (0);
}