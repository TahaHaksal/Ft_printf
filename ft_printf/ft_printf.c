/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:26:51 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:16:51 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_string(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	else
		return (ft_printf("(null)"));
}

int	ft_hub(char c, va_list params)
{
	int	j;

	if (c == 's')
		return ((j = ft_putstr(va_arg(params, char *))));
	else if (c == 'x' || c == 'X' || c == 'u')
		return ((j = ft_extract(c, va_arg(params, unsigned int))));
	else if (c == 'i' || c == 'd' || c == 'c')
		return ((j = ft_extract2(c, va_arg(params, int))));
	else if (c == 'p')
		return ((j = ft_vdptr(va_arg(params, unsigned long))));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		j;

	j = 0;
	va_start(params, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				j += ft_putchar(*s);
			else
				j += ft_hub(*s, params);
		}
		else
			j += ft_putchar(*s);
		s++;
	}
	va_end(params);
	return (j);
}
