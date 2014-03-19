/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:10:10 by cobrecht          #+#    #+#             */
/*   Updated: 2014/01/12 22:10:04 by cobrecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (ft_isspace(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i - 1] == '-')
		neg++;
	while (ft_isdigit(str[i]))
	{
		if (ft_isdigit(str[i]) && neg < 3)
		{
			nb = (nb * 10) + (str[i] - '0');
			if (neg == 0)
				neg = 2;
		}
		i++;
	}
	if (neg == 1)
		nb *= -1;
	return (nb);
}
