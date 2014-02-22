/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:03:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/22 10:55:51 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				command_get(t_cmd *cmd)
{
	char		*line;
	int			rtn;

	line = NULL;
	if (cmd->raw)
		free(cmd->raw);
	if ((rtn = get_next_line(0, &line)) == -1)
		return (error(16, NULL));
	cmd->hist = list_filling(cmd->hist, ft_strdup(line));
	print_hist(cmd);
	cmd->raw = line;
	return (rtn);
}
