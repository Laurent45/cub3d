/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:44:21 by lfrederi          #+#    #+#             */
/*   Updated: 2021/11/28 23:31:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_lenitoa(int n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_reverse(char *itoa, int lenitoa)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < lenitoa / 2)
	{
		tmp = itoa[i];
		itoa[i] = itoa[lenitoa - 1 - i];
		itoa[lenitoa - 1 - i] = tmp;
		i++;
	}
}

static void	ft_writeitoa(char *itoa, int n, int lenitoa, int neg)
{
	int				i;
	unsigned int	tmp;

	i = 0;
	if (n)
	{
		if (neg)
			tmp = n * -1;
		else
			tmp = n;
		while (tmp != 0)
		{
			itoa[i] = (tmp % 10) + '0';
			tmp /= 10;
			i++;
		}
		if (neg)
			itoa[i++] = '-';
	}
	else
		itoa[i++] = '0';
	itoa[i] = '\0';
	ft_reverse(itoa, lenitoa);
}

char	*ft_itoa(int n)
{
	int		lenitoa;
	char	*itoa;
	int		neg;

	lenitoa = ft_lenitoa(n);
	itoa = (char *) malloc(sizeof(char) * (lenitoa + 1));
	if (!itoa)
		return (NULL);
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	ft_writeitoa(itoa, n, lenitoa, neg);
	return (itoa);
}
