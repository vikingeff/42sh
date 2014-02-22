/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:52:41 by rmasse            #+#    #+#             */
/*   Updated: 2014/01/12 18:26:41 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

void		clear_key(char *key)
{
	key[1] = 0;
	key[2] = 0;
	read(0, key, 3);
}

void		set_esc_key(char *key)
{
	key[0] = 27;
	key[1] = 0;
	key[2] = 0;
}

int			tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
