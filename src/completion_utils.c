/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 12:15:31 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/28 16:40:15 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_find_rule(char *str, int index)
{
	if ((index - 1) > 0 && (str[index - 1] == '|'
		|| str[index - 1] == ';' || str[index - 1] == '`'))
		return (1);
	if ((index - 2) > 0)
		if ((str[index - 1] == '&' && str[index - 2] == '&')
			|| (str[index - 1] == '|' && str[index - 2] == '|'))
		return (1);
	if ((index - 1) > 0 && str[index - 1] == '|')
		return (1);
	return (0);
}

int				ft_find_status(char *str, int begin)
{
	int			rule;
	int			index;

	index = 0;
	rule = 1;
	while (str[index] && index <= begin)
	{
		if (!rule)
			rule = ft_find_rule(str, index);
		if (index == 0 || ft_special_char(str[index - 1]))
		{
			if (begin == index)
				return (rule);
			else
				rule = 0;
		}
		index++;
	}
	return (rule);
}
