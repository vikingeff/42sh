/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:23:38 by rda-cost          #+#    #+#             */
/*   Updated: 2014/05/13 12:15:00 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	newstr = NULL;
	if (s != NULL && f != NULL)
	{
		if ((newstr = ft_strdup(s)))
		{
			i = 0;
			while (newstr[i])
			{
				newstr[i] = f(i, newstr[i]);
				i++;
			}
		}
	}
	return (newstr);
}
