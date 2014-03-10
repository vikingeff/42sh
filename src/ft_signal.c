/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:07:35 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/28 17:03:37 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_get_signal(int n)
{
	t_cmd	*cmd;

	if (n == SIGINT)
	{
		if (kill(process_id, SIGINT) == -1)
		{
			cmd = ft_remember(NULL, NULL, NULL, 1);
			cmd->sig = 1;
			cmd->fdsave = dup(0);
			close(0);
		}
	}
}

void		ft_signal(void)
{
	signal(SIGINT, ft_get_signal);
}
