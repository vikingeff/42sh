/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:25:24 by cobrecht          #+#    #+#             */
/*   Updated: 2014/01/14 13:06:26 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*st1;
	const unsigned char	*st2;
	size_t				i;

	st1 = s1;
	st2 = s2;
	i = 0;
	while (i < n)
	{
		if (st1[i] - st2[i] != 0)
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
