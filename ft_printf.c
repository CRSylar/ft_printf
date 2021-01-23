/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:37:34 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 13:51:20 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params *g_ret;

void	ft_initgret(void)
{
	g_ret->sflag = 0;
	g_ret->zflag = 0;
	g_ret->printed = 0;
	g_ret->width = 0;
	g_ret->precision = -1;
	g_ret->ptr = 0;
	g_ret->intpart = 0;
	g_ret->decpart = 0;
	g_ret->plflag = 0;
	g_ret->tagflag = 0;
	g_ret->spflag = 0;
}

int		ft_start_read(const char *str)
{
	char	*cpy;

	cpy = ft_strdup(str);
	g_ret->printed = 0;
	while (*cpy)
	{
		if (*cpy == '%' && *(cpy + 1))
		{
			cpy++;
			ft_readflags(&cpy);
			ft_readwidth(&cpy);
			ft_readprec(&cpy);
			if (ft_start_conv(&cpy) == -1)
			{
				g_ret->printed = 0;
				return (g_ret->printed);
			}
			cpy++;
		}
		else
			g_ret->printed += ft_putchar_fd(*cpy++, 1);
	}
	free(cpy - ft_strlen(str));
	return (g_ret->printed);
}

int		ft_printf(const char *str, ...)
{
	if (!str)
		return (0);
	g_ret = (t_params*)malloc(sizeof(t_params));
	ft_initgret();
	va_start(g_ret->arg, str);
	ft_start_read(str);
	*(g_ret->ptr) = g_ret->printed;
	va_end(g_ret->arg);
	free(g_ret);
	return (g_ret->printed);
}
