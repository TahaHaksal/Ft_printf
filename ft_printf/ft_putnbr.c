/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:26:54 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:17:54 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

void	loop(int nb, int j, int len)
{
	if (nb == -2147483648)
	{
		write (1, "-2", 2);
		nb = nb % 1000000000;
		nb *= -1;
	}
	if (nb < 0)
	{
		nb *= -1;
		write (1, "-", 1);
	}
	j = nb;
	while (j > 9)
	{
		len *= 10;
		j /= 10;
	}
	while (len > 0)
	{
		ft_putchar((nb / len) + '0');
		nb %= len;
		len /= 10;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = 1;
	j = 0;
	loop(nb, j, len);
}
