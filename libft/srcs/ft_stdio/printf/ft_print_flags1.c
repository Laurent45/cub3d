/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:30:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/04/14 14:55:04 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_stdio.h"

int	ft_print_c(va_list *ap, t_args *args)
{
	int	len;

	len = 0;
	if (args->dot_flag >= 0)
		args->dot_flag = -1;
	len += ft_padding_blank(args, 0, 1);
	len += ft_putzero_zeroflag(args, 1);
	len += ft_putchar((char) va_arg(*ap, int));
	len += ft_left_adjustment(args, len);
	return (len);
}

int	ft_print_percent(t_args *arg)
{
	int	len;

	len = 0;
	if (arg->dot_flag > 0)
		arg->dot_flag = 0;
	len += ft_padding_blank(arg, 0, 1);
	len += ft_putzero_zeroflag(arg, 1);
	len += ft_putchar(arg->format);
	len += ft_left_adjustment(arg, len);
	return (len);
}

int	ft_print_s(va_list *ap, t_args *args)
{
	int		len;
	int		tmp;
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		len = 6;
	else
		len = ft_strlen_pf(s);
	if ((args->dot_flag < len) && (args->dot_flag >= 0))
		len = args->dot_flag;
	else
		args->dot_flag = len;
	tmp = len;
	len += ft_padding_blank(args, 0, tmp);
	len += ft_putzero_zeroflag(args, tmp);
	if (!s)
		ft_putstr("(null)", tmp);
	else
		ft_putstr(s, tmp);
	len += ft_left_adjustment(args, len);
	return (len);
}
