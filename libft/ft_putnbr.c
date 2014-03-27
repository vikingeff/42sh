/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:00:05 by cobrecht          #+#    #+#             */
/*   Updated: 2014/03/26 18:14:26 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		div;
	char	*str;

	str = "-2147483648";
	if (n != -2147483648)
	{
		div = 1;
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		if (n < 10)
			ft_putchar('0' + n);
	}
	else
		ft_putstr(str);
}
