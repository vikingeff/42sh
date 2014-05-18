/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:25:20 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:15:25 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
