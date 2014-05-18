/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:00:05 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:12 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;

	div = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	if (n > 0)
	{
		while (n > div * 10)
			div *= 10;
		while (n > 0)
		{
			ft_putchar_fd('0' + (n / div), fd);
			n %= div;
			div /= 10;
		}
	}
}
