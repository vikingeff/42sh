/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 13:33:16 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/19 15:27:53 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			term_close(t_env *env)
{
	term_put("ei");
	term_put("ve");
	free(env->term);
	term_canonical_mode(env->term, 1);
}