/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:39 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 13:44:04 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_intsflag(char *data, int ofset, char type)
{
	int h;
	int sign;

	h = 0;
	sign = 0;
	if (ft_zeroprec(data))
		return ;
	if (*data == '-')
	{
		g_ret->printed += ft_putchar_fd(*(data++), 1);
		sign = 1;
		g_ret->width--;
		ofset--;
	}
	else
		g_ret->printed += ft_dobonflag(0, type, data);
	if (!(g_ret->precision == 0 && (*data = '0')))
	{
		while ((g_ret->precision--) - ofset > 0)
			h += ft_putchar_fd('0', 1);
		h += ft_putstr_fd(data, -1, 1);
	}
	ft_pad(h);
	g_ret->printed += h;
	ft_free(data, sign);
}

void	ft_intzflag(char *data, int ofset, char type)
{
	int sign;

	sign = 0;
	if (ft_zeroprec(data))
		return ;
	if (*data == '-')
		g_ret->precision++;
	while ((g_ret->precision > 0) && (g_ret->width--) - ft_max(ofset) > 0)
		g_ret->printed += ft_putchar_fd(' ', 1);
	if (*data == '-')
	{
		g_ret->printed += ft_putchar_fd(*(data++), 1);
		g_ret->precision--;
		sign = 1;
	}
	else
		g_ret->printed += ft_dobonflag(0, type, data);
	while ((g_ret->precision < 0) && (g_ret->width--) - ft_max(ofset) > 0)
		g_ret->printed += ft_putchar_fd('0', 1);
	while ((g_ret->precision--) - (ofset - sign) > 0)
		g_ret->printed += ft_putchar_fd('0', 1);
	g_ret->printed += ft_putstr_fd(data, -1, 1);
	ft_free(data, sign);
}

void	ft_onwidprec(char *data, int ofset, char type)
{
	int sign;

	sign = 0;
	if (ft_zeroprec(data))
		return ;
	else
	{
		if (*data == '-')
		{
			g_ret->width--;
			ofset--;
			sign = 1;
		}
		else
			g_ret->printed += ft_dobonflag(0, type, data);
		ft_pad(ft_max(ofset));
		if (*data == '-')
			g_ret->printed += ft_putchar_fd(*(data++), 1);
		while ((g_ret->precision--) - ofset > 0)
			g_ret->printed += ft_putchar_fd('0', 1);
		g_ret->printed += ft_putstr_fd(data, -1, 1);
	}
	ft_free(data, sign);
}

void	ft_prechandle(char *data, int ofset, char type)
{
	int sign;

	sign = 0;
	if (ft_zeroprec(data))
		return ;
	if (*data == '-')
	{
		ofset--;
		sign = 1;
		g_ret->printed += ft_putchar_fd(*(data++), 1);
	}
	else
		g_ret->printed += ft_dobonflag(0, type, data);
	while (g_ret->precision-- > ofset)
		g_ret->printed += ft_putchar_fd('0', 1);
	g_ret->printed += ft_putstr_fd(data, -1, 1);
	ft_free(data, sign);
}

void	ft_convint(char *data, char type)
{
	int		ofset;

	ofset = ft_strlen(data);
	if (type == 'x' || type == 'X' || type == 'u')
		ft_clearflag(type, &ofset);
	if (g_ret->sflag)
		ft_intsflag(data, ofset, type);
	else if (g_ret->zflag)
		ft_intzflag(data, ofset, type);
	else if ((g_ret->width > g_ret->precision) && g_ret->precision >= 0)
		ft_onwidprec(data, ofset, type);
	else if (g_ret->width && g_ret->precision == -1)
	{
		ft_pad(ofset);
		g_ret->printed += ft_dobonflag(0, type, data);
		g_ret->printed += ft_putstr_fd(data, -1, 1);
	}
	else if (g_ret->precision > 0)
		ft_prechandle(data, ofset, type);
	else if (!(g_ret->precision == 0 && *data == '0'))
	{
		g_ret->printed += ft_dobonflag(0, type, data);
		g_ret->printed += ft_putstr_fd(data, g_ret->precision - 1, 1);
	}
}
