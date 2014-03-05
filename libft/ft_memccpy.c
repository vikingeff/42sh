/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:25:20 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/23 17:02:10 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*st1;
	const unsigned char	*st2;
	unsigned char		ct;

	ct = c;
	st1 = s1;
	st2 = s2;
	while (n > 0)
	{
		if (*st2 != ct)
			*st1 = *st2;
		else
		{
			*st1 = *st2;
			st1++;
			return (st1);
		}
		n--;
		st1++;
		st2++;
	}
	return (NULL);
}
