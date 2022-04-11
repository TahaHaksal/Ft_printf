/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:26:48 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:17:25 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_extract2(char c, int a)
{
	char	*ptr;
	int		i;

	if (c == 'c')
	{
		ft_putchar(a);
		return (1);
	}
	else
	{
		ptr = ft_itoa(a);
		i = ft_strlen(ptr);
		ft_putstr(ptr);
		free(ptr);
		return (i);
	}
}
