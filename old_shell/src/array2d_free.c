/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2d_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:51:00 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/03 18:14:15 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		array2d_free(char **array)
{
	int			i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}
