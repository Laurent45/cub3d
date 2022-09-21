/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:30:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/02/04 15:34:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../headers/ft_stdio.h"

int	ft_print_x(va_list *ap, t_args *arg)
{
	unsigned int	n;
	int				len;
	int				tmp;
	int				sharp;

	n = va_arg(*ap, unsigned int);
	tmp = ft_countdigit_ux(n, 16);
	sharp = 0;
	if (arg->sharp_flag && n)
		sharp = 2;
	if (!n && !arg->dot_flag)
		tmp = 0;
	len = tmp + sharp;
	if ((arg->dot_flag >= 0) && (arg->zero_flag == 1))
		arg->zero_flag = 0;
	if (arg->dot_flag > len)
		len += ft_padding_blank(arg, n, arg->dot_flag + sharp);
	else
		len += ft_padding_blank(arg, n, len);
	ft_put_sharpflag(arg, n, 0);
	len += ft_putzero_dotflag(arg, tmp) + ft_putzero_zeroflag(arg, len);
	if (tmp)
		ft_putnbr_x(n, 0);
	len += ft_left_adjustment(arg, len);
	return (len);
}

int	ft_print_xx(va_list *ap, t_args *arg)
{
	unsigned int	n;
	int				len;
	int				tmp;
	int				sharp;

	n = va_arg(*ap, unsigned int);
	tmp = ft_countdigit_ux(n, 16);
	sharp = 0;
	if (arg->sharp_flag && n)
		sharp = 2;
	if (!n && !arg->dot_flag)
		tmp = 0;
	len = tmp + sharp;
	if ((arg->dot_flag >= 0) && (arg->zero_flag == 1))
		arg->zero_flag = 0;
	if (arg->dot_flag > len)
		len += ft_padding_blank(arg, n, arg->dot_flag + sharp);
	else
		len += ft_padding_blank(arg, n, len);
	ft_put_sharpflag(arg, n, 1);
	len += ft_putzero_dotflag(arg, tmp) + ft_putzero_zeroflag(arg, len);
	if (tmp)
		ft_putnbr_x(n, 1);
	len += ft_left_adjustment(arg, len);
	return (len);
}

int	ft_print_u(va_list *ap, t_args *arg)
{
	unsigned int	n;
	int				len;
	int				tmp;

	n = va_arg(*ap, unsigned int);
	tmp = ft_countdigit_ux(n, 10);
	if (!n && !arg->dot_flag)
		tmp = 0;
	len = tmp;
	if ((arg->dot_flag >= 0) && (arg->zero_flag == 1))
		arg->zero_flag = 0;
	len += ft_padding_blank(arg, n, len);
	len += ft_putzero_dotflag(arg, tmp) + ft_putzero_zeroflag(arg, len);
	if (tmp)
		ft_putnbr_u(n);
	len += ft_left_adjustment(arg, len);
	return (len);
}

int	ft_print_p(va_list *ap, t_args *arg)
{
	unsigned long	p;
	int				len;
	int				tmp;

	p = va_arg(*ap, unsigned long);
	tmp = ft_countdigit_p(p);
	if (!p && !arg->dot_flag)
		tmp = 0;
	len = tmp + 2;
	if ((arg->dot_flag >= 0) && (arg->zero_flag == 1))
		arg->zero_flag = 0;
	if (arg->dot_flag > len)
		len += ft_padding_blank(arg, p, arg->dot_flag + 2);
	else
		len += ft_padding_blank(arg, p, len);
	write(1, "0x", 2);
	len += ft_putzero_dotflag(arg, tmp) + ft_putzero_zeroflag(arg, len);
	if (tmp)
		ft_putnbr_lux(p);
	len += ft_left_adjustment(arg, len);
	return (len);
}

int	ft_print_di(va_list *ap, t_args *arg)
{
	int	n;
	int	len;
	int	tmp;

	n = va_arg(*ap, int);
	tmp = ft_countdigit_d(n);
	if (!n && !arg->dot_flag)
		tmp = 0;
	len = tmp;
	if ((arg->dot_flag >= 0) && (arg->zero_flag == 1))
		arg->zero_flag = 0;
	len += ft_padding_blank(arg, n, len);
	if (n < 0)
		len += ft_putchar('-');
	if ((arg->sign_flag) && (n >= 0))
		len += ft_putchar('+');
	else if ((arg->blank_flag) && (n >= 0) && !arg->digit_padding)
		len += ft_putchar(' ');
	len += (ft_putzero_dotflag(arg, tmp) + ft_putzero_zeroflag(arg, len));
	if (tmp)
		ft_putnbr_d(n);
	len += ft_left_adjustment(arg, len);
	return (len);
}
