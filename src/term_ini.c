/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_ini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:37:37 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 00:47:05 by cobrecht         ###   ########.fr       */
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
	env->canon_save = env->term->c_lflag;
	return (0);
}