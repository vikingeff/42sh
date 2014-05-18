/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:25:20 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:28 by gleger           ###   ########.fr       */
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
