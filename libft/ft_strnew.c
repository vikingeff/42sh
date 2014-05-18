/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger   <gleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 08:38:48 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:14:55 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if ((str = (char*)malloc(sizeof(*str) * size)))
	{
		while (size)
		{
			str[size] = '\0';
			size--;
		}
		str[size] = '\0';
	}
	return (str);
}
