/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:58:49 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/20 18:43:18 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adrzflag(char *data, int len)
{
	if (*data == '0' && g_ret->precision == 0)
		len = 0;
	ft_pad(len + 2);
	g_ret->printed += ft_putstr_fd("0x", -1, 1);
	if (g_ret->precision == 0 && *data == '0' && len == 0)
		return ;
	while ((g_ret->precision--) - len > 0)
		g_ret->printed += ft_putchar_fd('0', 1);
	if (!(*data == '0' && len == 1 && g_ret->precision != 0))
		g_ret->printed += ft_putstr_fd(data, -1, 1);
	if (*data == '0' && len == 1)
	{
		while ((g_ret->precision--) > 0)
			g_ret->printed += ft_putchar_fd('0', 1);
		if (g_ret->precision < -1)
			g_ret->printed += ft_putchar_fd('0', 1);
	}
}

void	ft_convadrr(char *data)
{
	int		h;
	int		len;

	len = ft_strlen(data);
	if (g_ret->sflag)
	{
		h = ft_putstr_fd("0x", -1, 1);
		h += ft_putstr_fd(data, -1, 1);
		ft_pad(h);
		g_ret->printed += h;
	}
	else
		ft_adrzflag(data, len);
}
