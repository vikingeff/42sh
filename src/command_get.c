/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:03:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/12 18:13:58 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			command_get(t_cmd *cmd)
{
	char	*line;
	int		rtn;

	line = NULL;
	if (cmd->raw)
		free(cmd->raw);
	if ((rtn = get_next_line(0, &line)) == -1)
		return (error(16, NULL));
	cmd->raw = line;
	return (rtn);
}