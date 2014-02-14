/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 14:58:57 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/14 15:05:52 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_echo(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	index;
	int	opt;

	opt = 0;
	if (ft_strcmp(cmd->split[index], "-n") == 0)
		opt = 1;
	index = 1 + opt;
	while (cmd->split[index])
	{
		ft_putstr(cmd->split[index]);
		index++;
	}
	if (!opt)
		ft_putstr("\n");
	return (0);
}