/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:43:52 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:14:37 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(r = malloc(sizeof(*r) * (len + 1))))
		return (NULL);
	i = 0;
	while (len)
	{
		--len;
		r[i] = s[start + i];
		++i;
	}
	r[i] = 0;
	return (r);
}
