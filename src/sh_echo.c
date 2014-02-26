/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 14:58:57 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/14 19:18:34 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_echo(t_cmd *cmd, t_env *env, t_dir *dir)
{
	int	index;
	int	opt;

	opt = 0;
	if (cmd->split[1] && ft_strcmp(cmd->split[1], "-n") == 0)
		opt = 1;
	index = 1 + opt;
	while (cmd->split[index])
	{
		ft_putstr(cmd->split[index]);
		if (cmd->split[index + 1])
			ft_putstr(" ");
		index++;
	}
	if (!opt)
		ft_putstr("\n");
	return (0);
}