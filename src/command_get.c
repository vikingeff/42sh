/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:03:30 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/09 17:57:55 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			command_get(t_cmd *cmd)
{
	char	*line;
	int		rtn;

	line = NULL;
	if ((rtn = get_next_line(0, &line)) == -1)
		return (error(16, NULL));
	cmd->raw = line;
	return (rtn);
}