/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:37:42 by lfrederi          #+#    #+#             */
/*   Updated: 2021/11/29 12:53:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;
	size_t				i;

	if (!n)
		return (0);
	tmp_s1 = (const unsigned char *) s1;
	tmp_s2 = (const unsigned char *) s2;
	i = 0;
	while ((i < n - 1) && (tmp_s1[i] == tmp_s2[i]))
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
