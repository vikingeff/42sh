/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:59:02 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/22 08:20:01 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*st;

	st = s;
	while (n > 0)
	{
		st[n - 1] = '\0';
		n--;
	}
}
