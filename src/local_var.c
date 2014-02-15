/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:54:45 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/15 19:16:56 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_get_tmp_var(char *str)
{
	int	index;

	if (!str)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] < 0)
			str[index] = -1 * str[index];
		index++;
	}
	return (str);
}

static void		ft_find_var(t_cmd *cmd, t_env *env, int index, int count)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strsub(cmd->split[index], 0, count);
	tmp2 = ft_strsub(cmd->split[index], count + 1,
		ft_strlen(cmd->split[index]) - (count + 1));
	free(cmd->split[index]);
	tmp2 = ft_get_tmp_var(tmp2);
	cmd->split[index] = ft_strjoin(tmp1, env_get_value(tmp2, env));
	free(tmp1);
	free(tmp2);
}

void			ft_get_var(t_cmd *cmd, t_env *env)
{
	int		index;
	int		count;

	index = 0;
	while (cmd->split[index])
	{
		count = 0;
		while (cmd->split[index][count])
		{
			if (cmd->split[index][count] == '$')
			{
				ft_find_var(cmd, env, index, count);
				return ;
			}
			count++;
		}
		index++;
	}
}