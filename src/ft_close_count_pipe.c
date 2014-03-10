/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_count_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:55:48 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/14 11:57:46 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_close_pipe(int *fdpipe, int pipenb)
{
	int	index;

	index = 0;
	while (index < (2 * pipenb))
	{
		close(fdpipe[index]);
		index++;
	}
}

int			ft_count_pipe(t_list *arg)
{
	int	count;

	count = 0;
	while (arg)
	{
		if (ft_strcmp(arg->valeure, "|") == 0)
			count++;
		if (ft_strcmp(arg->valeure, "|") != 0)
			return (count);
		arg = arg->next;
	}
	return (0);
}