/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:56:08 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/14 18:56:22 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_get_var(t_cmd *cmd, t_env *env)
{
	int		index;
	int		count;
	char	*tmp1;
	char	*tmp2;

	index = 0;
	while (cmd->split[index])
	{
		count = 0;
		while (cmd->split[index][count])
		{
			if (cmd->split[index][count] == '$')
			{
				tmp1 = ft_strsub(cmd->split[index], 0, count);
				tmp2 = ft_strsub(cmd->split[index], count + 1, ft_strlen(cmd->split[index]) - (count + 1));
				free(cmd->split[index]);
				cmd->split[index] = ft_strjoin(tmp1, env_get_value(tmp2, env));
				free(tmp1);
				free(tmp2);
				break ;
			}
			count++;
		}
		index++;
	}
}

int				command_parse(t_cmd *cmd, t_env *env)
{
	int	index;
	int	count;

	index = 0;
	if (cmd->split)
		array2d_free(cmd->split);
	if (!(cmd->split = ft_strsplit_all(cmd->raw)))
		return (-1);
	ft_get_var(cmd, env);
	while (cmd->split[index])
	{
		count = 0;
		while (cmd->split[index][count])
		{
			if (cmd->split[index][count] < 0)
				cmd->split[index][count] = -1 * cmd->split[index][count];
			count++;
		}
		index++;
	}
	return (0);
}