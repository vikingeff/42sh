/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_table_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 10:41:39 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/28 18:58:47 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**copy_table_i(char **table, int index)
{
	char	**ret;
	int		count;

	count = 0;
	ret = malloc(sizeof(char*) * ft_tablen(table) - index + 1);
	while (table[index])
	{
		ret[count] = ft_strdup(table[index]);
		index++;
		count++;
	}
	ret[count] = NULL;
	return (ret);
}
