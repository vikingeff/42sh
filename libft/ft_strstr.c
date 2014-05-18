/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:26:06 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:14:39 by rda-cost         ###   ########.fr       */
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
