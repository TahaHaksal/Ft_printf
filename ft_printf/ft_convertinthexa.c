/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertinthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:26:36 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:17:31 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i++] = s[j];
		s[j--] = c;
	}
	return (s);
}

char	*ft_strupcase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] > 96 && str[a] < 123)
			str[a] -= 32;
		a++;
	}
	return (str);
}

char	*ft_convertinthexa(unsigned int fd)
{
	char	*ptr;
	int		i;

	if (fd == 0)
	{
		ptr = ft_strdup("0");
		return (ptr);
	}
	ptr = malloc(18);
	i = 0;
	while (fd > 0)
	{
		if (fd % 16 < 10)
			ptr[i] = fd % 16 + 48;
		else
			ptr[i] = 'a' + ((fd % 16) % 10);
		i++;
		fd /= 16;
	}
	ptr[i] = '\0';
	ft_strrev(ptr);
	return (ptr);
}

int	ft_prntul(unsigned int fd)
{
	int				len;
	unsigned int	tmp;
	int				i;

	len = 1;
	tmp = fd;
	i = 0;
	while (tmp > 9)
	{
		len *= 10;
		tmp /= 10;
	}
	tmp = fd;
	while (len > 0 && tmp != 0)
	{
		ft_putchar(fd / len + 48);
		i++;
		fd %= len;
		len /= 10;
	}
	if (tmp == 0)
		return (ft_putchar('0'));
	return (i);
}

int	ft_extract(char c, unsigned int nb)
{
	char	*s;
	int		i;

	if (c == 'x')
	{
		s = ft_convertinthexa(nb);
		ft_putstr(s);
		i = ft_strlen(s);
		free(s);
		return (i);
	}
	else if (c == 'X')
	{
		s = ft_strupcase(ft_convertinthexa(nb));
		ft_putstr(s);
		i = ft_strlen(s);
		free(s);
		return (i);
	}
	else
		return (ft_prntul(nb));
}
