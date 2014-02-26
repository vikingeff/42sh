/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:26:06 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/23 18:00:58 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + (i - j));
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}
