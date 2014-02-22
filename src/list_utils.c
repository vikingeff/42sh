/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:47:53 by rmasse            #+#    #+#             */
/*   Updated: 2014/02/14 18:44:29 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "shell.h"

char		*ft_strjoin_free(char *res, char *str)
{
	char		*tmp;

	tmp = ft_strdup(res);
	free(res);
	res = ft_strjoin(tmp, str);
	free(tmp);
	return (res);
}

char		*time_padding(char *src)
{
	int			sz;
	char		*zero;
	char		*dest;

	zero = "0";
	sz = ft_strlen(src);
	if (sz != 2)
	{
		dest = ft_strjoin(zero, src);
		free(src);
		return (dest);
	}
	else
		return (src);
}
