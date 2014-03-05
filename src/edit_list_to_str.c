/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 09:15:42 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/28 16:43:10 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*to_str(t_char *list);

/*
** take the edition list of charactere, concatenate them into a string and
** free the list.
*/

char			*edit_list_to_str(t_char *list, t_cmd *cmd, t_cur *cursor)
{
	char		*str;

	str = NULL;
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	str = to_str(list);
	while (list->prev)
		list = edit_char_del(list, cmd, cursor);
	list = edit_char_del(list, cmd, cursor);
	return (str);
}

static char		*to_str(t_char *list)
{
	char		*str;
	char		*temp;
	char		c[2] = {'\0', '\0'};

	str = NULL;
	temp = NULL;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		c[0] = (char)list->c;
		if (str)
			free(str);
		str = ft_strjoin(temp, c);
		if (temp)
			free(temp);
		temp = ft_strdup(str);
		list = list->next;
	}
	free(temp);
	return (str);
}
