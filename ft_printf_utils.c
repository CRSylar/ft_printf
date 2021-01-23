/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:16 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/20 18:52:41 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad(int len)
{
	if (g_ret->zflag)
	{
		while ((g_ret->width--) - len > 0)
			g_ret->printed += ft_putchar_fd('0', 1);
	}
	else
	{
		while ((g_ret->width--) - len > 0)
			g_ret->printed += ft_putchar_fd(' ', 1);
	}
}

int		ft_min(int ofset)
{
	if (ofset < g_ret->precision)
		return (ofset);
	else
		return (g_ret->precision);
}

int		ft_max(int ofset)
{
	if (ofset > g_ret->precision)
		return (ofset);
	return (g_ret->precision);
}

void	ft_free(char *data, int sign)
{
	if (!sign)
		free(data);
	else
		free(data - 1);
}

int		ft_putfloat_fd(char *s, int len, int fd)
{
	int i;

	i = 0;
	if (!s || !len)
		return (i);
	if (len == -1)
		len = 7;
	while (s[i] && (len >= 0))
	{
		write(fd, &s[i], 1);
		i++;
		len--;
	}
	while (len-- >= 0)
		write(fd, "0", 1);
	return (i);
}
