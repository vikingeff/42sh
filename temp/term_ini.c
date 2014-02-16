/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:37:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/16 16:19:00 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		term_ini(t_env *env)
{
	char	*n_term;

	if ((n_term = getenv("TERM")) == NULL)
		return (error(0));
	if (tgetent(NULL, n_term) == -1)
		return (error(1));
	if (tcgetattr(0, env->term) == -1)
		return (error(2));
	env->term->c_cc[VMIN] = 1;
	env->term->c_cc[VTIME] = 0;
	if (term_canonical_mode(env->term, 0))
		return (-1);
	term_put("im");
	return (1);
}