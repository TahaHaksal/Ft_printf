/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:25:12 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:28:09 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*rev(char *s)
{
	int		i;
	int		len;
	char	ptr;

	i = 0;
	len = ft_strlen(s) - 1;
	while (len > i)
	{
		ptr = s[i];
		s[i] = s[len];
		s[len] = ptr;
		len--;
		i++;
	}
	return (s);
}

static int	t_count(int buff)
{
	int	i;

	i = 0;
	while (buff != 0)
	{
		buff /= 10;
		i++;
	}
	return (i);
}

static char	*save(int n, char *ptr)
{
	int	i;

	if (n == 0)
	{
		*ptr = '0';
		return (ptr);
	}
	i = 0;
	while (n != 0)
	{
		ptr[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	ptr[i] = '\0';
	rev(ptr);
	return (ptr);
}

static char	*t_intmin(char *ptr, int n)
{
	ptr[0] = '-';
	ptr[1] = '2';
	save(-1 * (n % 1000000000), &ptr[2]);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	i = t_count(n);
	if (n <= 0)
		i++;
	ptr = (char *) malloc(i + 1);
	if (!ptr)
		return (NULL);
	if (n == -2147483648)
		return (t_intmin(ptr, n));
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
		save(n, &ptr[1]);
	}
	else
		save(n, ptr);
	return (ptr);
}
