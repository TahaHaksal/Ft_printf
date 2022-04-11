/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:27:23 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/07 09:37:15 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putnbr(int nb);

int		ft_putchar(char c);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_extract(char c, unsigned int nb);
int		ft_extract2(char c, int a);
int		ft_vdptr(unsigned long ptr);

size_t	ft_strlen(const char *s);

char	*ft_strrev(char *s);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

#endif
