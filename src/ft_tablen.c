/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:10:20 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/11 19:15:13 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}