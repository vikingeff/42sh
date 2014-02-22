/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:47:53 by rmasse            #+#    #+#             */
/*   Updated: 2014/02/22 14:05:23 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "shell.h"

char		*ft_strjoin_free(char *res, char *str)
{
	char		*tmp;

	tmp = ft_strdup(res);
	free(res);
	res = ft_strjoin(tmp, str);
	free(tmp);
	return (res);
}

char		*time_padding(char *src)
{
	int			sz;
	char		*zero;
	char		*dest;

	zero = "0";
	sz = ft_strlen(src);
	if (sz != 2)
	{
		dest = ft_strjoin(zero, src);
		free(src);
		return (dest);
	}
	else
		return (src);
}

void			del_hist(t_cmd *cmd)
{
	t_hist 		*save;
	t_hist 		*tmp;

	save = cmd->hist;
	while (save->prev)
		save = save->prev;
	while (save)
	{
		free(save->time);
		free(save->data);
		save->data = NULL;
		save->time = NULL;
		tmp = save->next;
		save->next = NULL;
		save->prev = NULL;
		free(save);
		save = NULL;
		save = tmp;
	}
}

int		hist_is_valid(t_cmd *cmd)
{
	if (cmd->split[1])
	{
		if (!(ft_strcmp(cmd->split[1], "-c")))
		{
			del_hist(cmd);
			return (-1);
		}
		else if (ft_isdigit(cmd->split[1][0]))
			return (ft_atoi(cmd->split[1]));
		else
			return(error(7, NULL));
	}
	return (5000);
}