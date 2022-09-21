/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:53:53 by lfrederi          #+#    #+#             */
/*   Updated: 2022/02/04 15:50:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_stdio.h"
#include <unistd.h>

int	ft_padding_blank(t_args *arg, long n, int s)
{
	int	z;
	int	l;

	z = 0;
	if ((arg->dot_flag - s) > 0)
		z = arg->dot_flag - s;
	if (arg->digit_padding && !arg->zero_flag)
	{
		l = arg->digit_padding - arg->sign_flag - s - z;
		if (n >= 0)
			return (ft_putblank(l));
		else
			return (ft_putblank(l - 1));
	}
	return (0);
}

int	ft_left_adjustment(t_args *arg, int len)
{
	if ((arg->minus_flag))
		return (ft_putblank(arg->minus_flag - len));
	return (0);
}

int	ft_putzero_dotflag(t_args *arg, int len)
{
	if ((arg->dot_flag - len) > 0)
		return (ft_putzero(arg->dot_flag - len));
	return (0);
}

int	ft_putzero_zeroflag(t_args *arg, int len)
{
	if ((arg->zero_flag) && ((arg->digit_padding - len) > 0))
		return (ft_putzero(arg->digit_padding - len));
	return (0);
}

void	ft_put_sharpflag(t_args *arg, unsigned int n, int upper)
{
	if (arg->sharp_flag && n)
	{
		if (upper)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}
}
