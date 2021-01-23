/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:49:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/21 12:53:23 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arrotondo(int len)
{
	int		i;
	char	*check;

	i = g_ret->precision;
	check = !i ? "C" : 0;
	if (g_ret->decpart[i + 1] >= '5')
	{
		while (((!check) && (g_ret->decpart[i] =
			(g_ret->decpart[i] - '0' + 1) % 10 + '0') == '0'))
			if (g_ret->decpart[--i] == '.')
				check = "C";
		if (check)
		{
			while (((--len >= 0) && (g_ret->intpart[len] =
			(g_ret->intpart[len] - '0' + 1) % 10 + '0') == '0'))
				;
			if (len < 0)
			{
				check = ft_strjoin("1", g_ret->intpart);
				free(g_ret->intpart);
				g_ret->intpart = check;
			}
		}
	}
	return (1);
}

int		ft_dobonflag(int h, char type, char *data)
{
	if ((g_ret->plflag) && (!(*data) || (*data != '-')))
	{
		h += ft_putchar_fd('+', 1);
		g_ret->width--;
	}
	else if (g_ret->spflag)
	{
		h += ft_putchar_fd(' ', 1);
		g_ret->width--;
	}
	else if ((g_ret->tagflag) && ((type == 'x') || (type == 'X')))
	{
		if ((type == 'x') && (*data != '0'))
			h += ft_putstr_fd("0x", -1, 1);
		else if ((type == 'X') && (*data != '0'))
			h += ft_putstr_fd("0X", -1, 1);
		g_ret->width -= 2;
	}
	return (h);
}

void	ft_ntype(int *num)
{
	num = g_ret->ptr;
}

void	ft_bonusflag(char **str)
{
	if (**str == '+')
	{
		g_ret->plflag = 1;
		(*str)++;
	}
	else if (**str == ' ')
	{
		g_ret->spflag = 1;
		(*str)++;
	}
	else if (**str == '#')
	{
		g_ret->tagflag = 1;
		(*str)++;
	}
}

void	ft_bonus(char **cpy)
{
	if (**cpy == 'n')
		ft_ntype(va_arg(g_ret->arg, int*));
	else if (**cpy == 'f')
		ft_floatconv(ft_dtoa(va_arg(g_ret->arg, double),
					&(g_ret->intpart), &(g_ret->decpart)));
}
