/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:21:51 by rda               #+#    #+#             */
/*   Updated: 2014/01/19 10:57:10 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_to_null(t_list *list)
{
	list->next = NULL;
	list->prev = NULL;
	list->mot = NULL;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*newlist;

	if (!(newlist = ft_memalloc(sizeof(*newlist))))
		return (NULL);
	newlist->valeure = NULL;
	if (!content)
		ft_to_null(newlist);
	else
	{
		newlist->next = NULL;
		newlist->prev = NULL;
		newlist->mot = ft_strdup(content);
		newlist->dir = NULL;
		newlist->fd = 0;
	}
	return (newlist);
}
