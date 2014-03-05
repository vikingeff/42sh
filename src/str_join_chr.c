/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:49:35 by cobrecht          #+#    #+#             */
/*   Updated: 2014/02/03 18:14:27 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*str_join_chr(char const *s1, char const *s2, char c)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = malloc(sizeof(*r) * (i + 2))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		++i;
	}
	j = 0;
	r[i] = c;
	i++;
	while (s2 && s2[j])
	{
		r[i] = s2[j];
		++i;
		++j;
	}
	r[i] = 0;
	return (r);
}
