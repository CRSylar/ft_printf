/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:44:40 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 13:49:15 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convstring(char *str)
{
	int		ofset;
	int		h;

	if (!str)
		str = "(null)";
	ofset = ft_strlen(str);
	h = g_ret->precision - ofset;
	if (g_ret->sflag)
	{
		h = ft_putstr_fd(str, g_ret->precision, 1);
		g_ret->printed += h;
		ft_pad(h);
		return ;
	}
	else if ((g_ret->width) && g_ret->precision != -1)
	{
		ft_pad(ft_min(ofset));
		g_ret->printed += ft_putstr_fd(str, g_ret->precision, 1);
		return ;
	}
	else if (g_ret->width)
		ft_pad(ofset);
	g_ret->printed += ft_putstr_fd(str, g_ret->precision, 1);
}

void	ft_convchar(void)
{
	if (g_ret->sflag)
	{
		g_ret->printed += ft_putchar_fd((char)va_arg(g_ret->arg, int), 1);
		g_ret->width--;
		ft_pad(0);
		return ;
	}
	else if (g_ret->width--)
	{
		ft_pad(0);
		g_ret->printed += ft_putchar_fd((char)va_arg(g_ret->arg, int), 1);
		return ;
	}
	g_ret->printed += ft_putchar_fd((char)va_arg(g_ret->arg, int), 1);
}

void	ft_xcent(void)
{
	if (g_ret->sflag)
	{
		g_ret->printed += ft_putchar_fd('%', 1);
		g_ret->width--;
		ft_pad(0);
		return ;
	}
	else if (g_ret->zflag && g_ret->width--)
	{
		while (g_ret->width--)
			g_ret->printed += ft_putchar_fd('0', 1);
		g_ret->printed += ft_putchar_fd('%', 1);
		return ;
	}
	else if (g_ret->width--)
	{
		ft_pad(0);
		g_ret->printed += ft_putchar_fd('%', 1);
		return ;
	}
	g_ret->printed += ft_putchar_fd('%', 1);
}
