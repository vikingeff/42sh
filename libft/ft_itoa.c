/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:02:41 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:30 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n, int *divide)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		*divide *= 10;
		n /= 10;
		len++;
	}
	return (len);
}

static char		*ft_transcription(int n, int divide, int len, int neg)
{
	int		i;
	int		ntmp;
	char	*str;

	str = ft_strnew(len);
	i = 0;
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	while (len > 0)
	{
		ntmp = n;
		str[i] = ((ntmp / divide) + '0');
		n %= divide;
		divide /= 10;
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		divide;
	char	*str;

	len = 0;
	if (n != -2147483648)
	{
		neg = 0;
		divide = 1;
		if (n < 0)
		{
			n *= -1;
			neg = 1;
			len++;
		}
		len = ft_nbrlen(n, &divide);
		str = ft_transcription(n, divide, len, neg);
	}
	else
	{
		str = ft_strnew(11);
		str = ft_strcpy(str, "-2147483648");
	}
	return (str);
}
