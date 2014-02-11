/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 20:56:08 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/03 21:54:24 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				command_parse(t_cmd *cmd)
{
	if (!(cmd->split = ft_strsplit(cmd->raw, ' ')))
		return (-1);
	return (0);
}