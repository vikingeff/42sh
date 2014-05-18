/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:01:39 by rda-cost          #+#    #+#             */
/*   Updated: 2014/03/27 09:16:23 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int				ft_parse_arg(t_list *arg)
{
	t_list	*test;
	t_list	*dir;

	test = arg;
	while (test)
	{
		if (!test->mot || test->mot[0] == 0)
		{
			error(5, NULL);
			return (1);
		}
		dir = test->dir;
		while (dir)
		{
			if (!dir->valeure || dir->valeure[0] == 0)
			{
				error(6, NULL);
				return (1);
			}
			dir = dir->next;
		}
		test = test->next;
	}
	return (0);
}
