/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 22:29:38 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 18:17:00 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	new_str = NULL;
	if (s1)
	{
		while (s1[len])
			len++;
		if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
			return (new_str);
		while (i < len)
		{
			new_str[i] = s1[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
