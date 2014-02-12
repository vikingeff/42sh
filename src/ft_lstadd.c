/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 09:34:51 by rda               #+#    #+#             */
/*   Updated: 2014/01/19 11:45:02 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	cur = new;
	while (cur->next)
		cur = cur->next;
	cur->next = *alst;
	*alst = new;
}

t_list	*ft_lstadd_first(t_list *lst, t_list *new)
{
	t_list	*save;

	if (lst == NULL)
		return (new);
	save = lst;
	while (lst->next)
	lst = lst->next;
	lst->next = new;
	new->prev = lst;
	return (save);
}