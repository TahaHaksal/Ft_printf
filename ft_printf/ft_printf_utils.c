/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:18:16 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:26:13 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (src[a] != '\0')
		a++;
	if (size != 0)
	{
		while (src[b] != '\0' && b < size - 1)
		{
			dest[b] = src[b];
			b++;
		}
		dest[b] = '\0';
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s1);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, i + 1);
	return (ptr);
}
