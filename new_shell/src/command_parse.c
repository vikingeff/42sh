/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:56:08 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/11 17:49:00 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				command_parse(t_cmd *cmd)
{
	if (cmd->split)
		array2d_free(cmd->split);
	if (!(cmd->split = ft_strsplit_all(cmd->raw)))
		return (-1);
	return (0);
}