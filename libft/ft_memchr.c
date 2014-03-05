/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:03:05 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/21 20:14:19 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*st;
	size_t				i;

	st = s;
	i = 0;
	while (i < n)
	{
		if (st[i] == (unsigned char)c)
			return ((void*)s++);
		s++;
		i++;
	}
	return (NULL);
}
