/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 13:41:19 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/19 14:37:10 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_cmd(void)
{
	pid_t	pid_trol;
	char	**table;

	if ((pid_trol = fork()) == 0)
	{
		table = ft_strsplit("cat MAN/cmd", ' ');
		execve("/bin/cat", table, NULL);
	}
	else
		wait(NULL);
}