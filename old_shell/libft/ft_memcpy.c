/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:25:20 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/23 16:19:22 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* s1 and s2 must be at least n bytes, bug with void value as arguments*/
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*st1;
	const unsigned char	*st2;

	st1 = s1;
	st2 = s2;
	while (n > 0)
	{
		*st1 = *st2;
		st1++;
		st2++;
		n--;
	}
	return (s1);
}
