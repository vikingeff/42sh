/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:18:48 by cobrecht          #+#    #+#             */
/*   Updated: 2013/11/22 16:26:10 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	newstr = NULL;
	if (s != NULL && f != NULL)
	{
		if ((newstr = ft_strdup(s)))
		{
			i = 0;
			while (newstr[i])
			{
				newstr[i] = f(newstr[i]);
				i++;
			}
		}
	}
	return (newstr);
}
