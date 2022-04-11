/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:26:57 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:16:33 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convertinthexaul(unsigned long fd)
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

int	ft_vdptr(unsigned long ptr)
{
	char	*s;
	int		i;

	s = ft_convertinthexaul(ptr);
	ft_printf("0x");
	ft_printf(s);
	i = ft_strlen(s) + 2;
	free(s);
	return (i);
}
