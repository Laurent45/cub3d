/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:18:26 by lfrederi          #+#    #+#             */
/*   Updated: 2022/04/14 14:55:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(const char *s, int size)
{
	write(1, s, size);
	return (size);
}

int	ft_strlen_pf(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putzero(int n)
{
	int	tmp;

	tmp = n;
	while (tmp > 0)
	{
		write(1, "0", 1);
		tmp--;
	}
	return (n);
}

int	ft_putblank(int n)
{
	int	tmp;

	if (n <= 0)
		return (0);
	tmp = n;
	while (tmp > 0)
	{
		write(1, " ", 1);
		tmp--;
	}
	return (n);
}
