/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger   <gleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:19:13 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:03 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = malloc(sizeof(*r) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		r[i++] = s2[j++];
	r[i] = 0;
	return (r);
}
