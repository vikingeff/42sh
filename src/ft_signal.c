/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:07:35 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/12 19:08:07 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_get_signal(int n)
{
	if (n == SIGINT)
	{
		if (kill(process_id, SIGINT) == -1)
		{
			ft_putstr("\n");
			prompt_display(NULL);
		}
	}
}

void		ft_signal(void)
{
	signal(SIGINT, ft_get_signal);
}
