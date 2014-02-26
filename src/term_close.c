/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 13:33:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 00:49:32 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			term_close(t_env *env)
{
	term_put("ei");
	term_put("ve");
	term_canonical_mode(env, 1);
	free(env->term);
}