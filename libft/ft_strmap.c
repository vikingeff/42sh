/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:18:48 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:15:01 by rda-cost         ###   ########.fr       */
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
