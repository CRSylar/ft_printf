/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:38:16 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 14:09:04 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_params
{
	int			sflag;
	int			zflag;
	int			printed;
	int			width;
	int			precision;
	int			*ptr;
	char		*intpart;
	char		*decpart;
	int			plflag;
	int			spflag;
	int			tagflag;

	va_list		arg;
}				t_params;

extern t_params *g_ret;

int				ft_printf(const char *str, ...);
int				ft_start_read(const char *str);
int				ft_min(int ofset);
int				ft_max(int ofset);
int				ft_start_conv(char **cpy);
int				ft_zeroprec(char *data);
void			ft_convstring(char *str);
void			ft_convchar();
void			ft_xcent();
void			ft_intsflag(char *data, int ofset, char type);
void			ft_intzflag(char *data, int ofset, char type);
void			ft_onwidprec(char *data, int ofset, char type);
void			ft_prechandle(char *data, int ofset, char type);
void			ft_convint(char *data, char type);
void			ft_pad(int len);
void			ft_initgret();
void			ft_adrzflag(char *data, int len);
void			ft_convadrr(char *data);
void			ft_readprec(char **str);
void			ft_readwidth(char **str);
void			ft_readflags(char **str);
void			ft_free(char *data, int sign);
void			ft_clearflag(char type, int *ofset);

void			ft_bonus(char **cpy);
void			ft_bonusflag(char **str);
void			ft_flosflag(int intlen);
void			ft_flozflag(int intlen, int ofset);
void			ft_flwidprec(int intlen, int ofset);
void			ft_floatprec(int intlen);
void			ft_floatconv(int intlen);
int				ft_putfloat_fd(char *s, int len, int fd);
int				ft_dobonflag(int h, char type, char *data);
int				ft_arrotondo(int len);

#endif
