/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:45:27 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/21 12:52:31 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flosflag(int intlen)
{
	int h;
	int sign;

	sign = 0;
	h = 0;
	if (*(g_ret->intpart) == '-')
	{
		g_ret->printed += ft_putchar_fd(*(g_ret->intpart++), 1);
		sign = 1;
		g_ret->width--;
		intlen--;
	}
	else
		h += ft_dobonflag(h, 'z', g_ret->intpart);
	h += ft_putstr_fd(g_ret->intpart, -1, 1);
	if (!(g_ret->precision == 0 && (*(g_ret->intpart) = '0')))
		h += ft_putfloat_fd(g_ret->decpart, g_ret->precision, 1);
	(g_ret->precision > 0) ? g_ret->width-- : sign * 1;
	(g_ret->plflag || g_ret->spflag) ? g_ret->width++ : sign * 1;
	ft_pad(h);
	g_ret->printed += h;
	ft_free(g_ret->intpart, sign);
	free(g_ret->decpart);
}

void	ft_flozflag(int intlen, int ofset)
{
	int sign;

	sign = 0;
	if (*(g_ret->intpart) == '-')
		g_ret->precision++;
	g_ret->printed = ft_dobonflag(0, 'z', g_ret->intpart);
	(g_ret->precision > 0) ? g_ret->width-- : sign * 1;
	while ((g_ret->precision > 0) &&
			((g_ret->width--) - ft_max(ft_min(ofset) + intlen) > 0))
		g_ret->printed += ft_putchar_fd('0', 1);
	if (*(g_ret->intpart) == '-')
	{
		g_ret->printed += ft_putchar_fd(*(g_ret->intpart++), 1);
		g_ret->precision--;
		sign = 1;
	}
	while ((g_ret->precision < 0) &&
			((g_ret->width--) - ft_max(ofset + intlen) > 0))
		g_ret->printed += ft_putchar_fd('0', 1);
	g_ret->printed += ft_putstr_fd(g_ret->intpart, -1, 1);
	if (g_ret->precision == -1)
		g_ret->precision = 6;
	g_ret->printed += ft_putfloat_fd(g_ret->decpart, g_ret->precision, 1);
	ft_free(g_ret->intpart, sign);
	free(g_ret->decpart);
}

void	ft_flwidprec(int intlen, int ofset)
{
	int sign;

	sign = 0;
	if ((g_ret->precision == 0) &&
			((*(g_ret->intpart) == '0') && (g_ret->width)))
		ft_pad(0);
	else
	{
		if (*(g_ret->intpart) == '-')
		{
			g_ret->width--;
			intlen--;
			sign = 1;
		}
		(g_ret->precision > 0) ? g_ret->width-- : sign * 1;
		(g_ret->plflag || g_ret->spflag) ? g_ret->width-- : sign * 1;
		ft_pad(ft_max(ft_min(ofset) + intlen));
		g_ret->printed += ft_dobonflag(0, 'z', g_ret->intpart);
		if (*(g_ret->intpart) == '-')
			g_ret->printed += ft_putchar_fd(*(g_ret->intpart++), 1);
		g_ret->printed += ft_putstr_fd(g_ret->intpart, -1, 1);
		g_ret->printed += ft_putfloat_fd(g_ret->decpart, g_ret->precision, 1);
	}
	ft_free(g_ret->intpart, sign);
	free(g_ret->decpart);
}

void	ft_floatprec(int intlen)
{
	int sign;

	sign = 0;
	if (*(g_ret->intpart) == '-')
	{
		intlen--;
		sign = 1;
		g_ret->printed += ft_putchar_fd(*(g_ret->intpart++), 1);
	}
	else
		g_ret->printed += ft_dobonflag(0, 'z', g_ret->intpart);
	g_ret->printed += ft_putstr_fd(g_ret->intpart, -1, 1);
	g_ret->printed += ft_putfloat_fd(g_ret->decpart, g_ret->precision, 1);
	ft_free(g_ret->intpart, sign);
	free(g_ret->decpart);
}

void	ft_floatconv(int intlen)
{
	int ofset;

	if (ft_arrotondo(intlen) && !intlen)
		return ;
	ofset = ft_strlen(g_ret->decpart);
	if (g_ret->sflag)
		ft_flosflag(intlen);
	else if (g_ret->zflag)
		ft_flozflag(intlen, ofset);
	else if ((g_ret->width > g_ret->precision) && g_ret->precision >= 0)
		ft_flwidprec(intlen, ofset);
	else if (g_ret->width && g_ret->precision == -1)
	{
		ft_pad(ofset + intlen);
		g_ret->printed += ft_putstr_fd(g_ret->intpart, -1, 1);
		g_ret->printed += ft_putfloat_fd(g_ret->decpart, 6, 1);
	}
	else if (g_ret->precision > 0)
		ft_floatprec(intlen);
	else if (g_ret->precision == 0)
		g_ret->printed += ft_putstr_fd(g_ret->intpart, g_ret->precision - 1, 1);
	if (g_ret->precision < 0)
		g_ret->printed += ft_putstr_fd(g_ret->intpart, g_ret->precision - 1, 1);
	if (g_ret->precision < 0)
		g_ret->printed += ft_putfloat_fd(g_ret->decpart, 6, 1);
}
