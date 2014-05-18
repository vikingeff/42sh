/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:25:24 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:26 by gleger           ###   ########.fr       */
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
