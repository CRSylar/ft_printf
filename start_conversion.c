/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:44:11 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 13:51:56 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zeroprec(char *data)
{
	if ((g_ret->precision == 0) && (*data == '0'))
	{
		g_ret->zflag = 0;
		if (g_ret->plflag || g_ret->spflag)
			g_ret->width--;
		ft_pad(0);
		g_ret->printed += ft_dobonflag(0, 'z', data);
		return (1);
	}
	return (0);
}

int		ft_start_conv(char **cpy)
{
	if (**cpy == '%')
		ft_xcent();
	else if (**cpy == 's')
		ft_convstring(va_arg(g_ret->arg, char*));
	else if (**cpy == 'c')
		ft_convchar();
	else if ((**cpy == 'd') || **cpy == 'i')
		ft_convint(ft_itoa(va_arg(g_ret->arg, int)), 'd');
	else if ((**cpy == 'u') || (**cpy == 'x') || (**cpy == 'X'))
	{
		if (**cpy == 'X')
			ft_convint(ft_stoa_b(va_arg(g_ret->arg, unsigned int), 'H'), 'X');
		else if (**cpy == 'x')
			ft_convint(ft_stoa_b(va_arg(g_ret->arg, unsigned int), 'h'), 'x');
		else
			ft_convint(ft_stoa_b(va_arg(g_ret->arg, unsigned int), 'd'), 'd');
	}
	else if (**cpy == 'p')
		ft_convadrr(ft_stoa_b(va_arg(g_ret->arg, size_t), 'h'));
	else if (**cpy == 'n' || **cpy == 'f')
		ft_bonus(cpy);
	else
		return ((g_ret->printed = -1));
	return (g_ret->printed);
}
