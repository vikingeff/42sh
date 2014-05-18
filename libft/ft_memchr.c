/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger   <gleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:03:05 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:28 by gleger           ###   ########.fr       */
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
