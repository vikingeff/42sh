/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 18:26:37 by rda-cost          #+#    #+#             */
/*   Updated: 2014/02/14 12:08:10 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}

void	ft_dup2(int newfd, int oldfd)
{
	if (dup2(newfd, oldfd) == -1)
	{
		ft_putstr("Dup2 Error\n");
		exit(0);
	}
}

t_list	*ft_add_arg(char *str, char *type, t_list *list)
{
	t_list	*save;

	list = ft_lstadd_first(list, ft_lstnew(str));
	save = list;
	while (list->next)
		list = list->next;
	list->valeure = ft_strdup(type);
	list = save;
	return (list);
}

void	ft_close(int fd[2])
{
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 1 && fd[1] != 0)
		close(fd[1]);
}
