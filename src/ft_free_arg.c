/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:44:49 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/12 19:51:05 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list	*ft_free_one(t_list *list)
{
	free(list->mot);
	free(list->valeure);
	if (list->next != NULL)
	{
		list = list->next;
		free(list->prev);
	}
	else
	{
		free(list);
		list = NULL;
	}
	return (list);
}

void	ft_free_arg(t_list *arg)
{
	while (arg)
	{
		while (arg->dir)
			arg->dir = ft_free_one(arg->dir);
		arg = ft_free_one(arg);
	}
}
