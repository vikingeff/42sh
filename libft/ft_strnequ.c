/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:37:28 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/22 09:44:39 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if ((s1 != NULL && s2 != NULL))
	{
		while (s1[i] == s2[i])
		{
			if ((s1[i] == '\0' && s2[i] == '\0') || n == 1)
				return (1);
			i++;
			n--;
		}
	}
	return (0);
}
