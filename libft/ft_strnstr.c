/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger   <gleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:31:21 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:14:41 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i] == s2[j] && i < n)
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
