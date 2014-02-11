/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:45:34 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/20 20:19:05 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	diff = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
