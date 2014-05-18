/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger   <gleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:41:32 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:23 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bt;

	bt = b;
	i = 0;
	while (i < len)
	{
		bt[i] = (char)c;
		i++;
	}
	return (b);
}
