/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagshandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:39:42 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/21 12:54:05 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clearflag(char type, int *ofset)
{
	if (type == 'u')
	{
		g_ret->tagflag = 0;
		g_ret->plflag = 0;
		g_ret->spflag = 0;
	}
	else
	{
		g_ret->plflag = 0;
		g_ret->spflag = 0;
	}
	if ((g_ret->tagflag) && (g_ret->precision < 0))
		*ofset += 2;
}

void	ft_readprec(char **str)
{
	int len;

	len = 0;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			if ((g_ret->precision = va_arg(g_ret->arg, int)) < 0)
				g_ret->precision = -1;
			(*str)++;
			return ;
		}
		while (**str == '0')
			(*str)++;
		g_ret->precision = ft_atoi(*str);
		len = ft_intlen(g_ret->precision);
		if (g_ret->precision != 0)
			*str += len;
	}
	else
		g_ret->precision = -1;
}

void	ft_readwidth(char **str)
{
	int		len;

	len = 0;
	if (**str == '*')
	{
		if ((g_ret->width = va_arg(g_ret->arg, int)) < 0)
		{
			g_ret->width = -g_ret->width;
			g_ret->sflag = 1;
			g_ret->zflag = 0;
		}
		(*str)++;
		return ;
	}
	while (**str == '0')
		(*str)++;
	if ((**str > '0') && (**str <= '9'))
	{
		g_ret->width = ft_atoi(*str);
		len = ft_intlen(g_ret->width);
		*str += len;
		return ;
	}
	g_ret->width = 0;
}

void	ft_readflags(char **str)
{
	ft_bonusflag(str);
	if (**str == '-')
	{
		g_ret->sflag = 1;
		(*str)++;
		if (**str == '0')
			(*str)++;
		ft_bonusflag(str);
		return ;
	}
	else if (**str == '0')
	{
		while (**str == '0')
			(*str)++;
		ft_bonusflag(str);
		g_ret->zflag = 1;
		if (**str == '-')
		{
			g_ret->sflag = 1;
			g_ret->zflag = 0;
			(*str)++;
		}
		ft_bonusflag(str);
		return ;
	}
}
