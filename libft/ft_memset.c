/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:41:32 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/21 17:55:30 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/* behavior is undefined if b == NULL or len > b length */
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
