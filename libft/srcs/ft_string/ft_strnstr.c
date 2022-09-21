/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:57:09 by lfrederi          #+#    #+#             */
/*   Updated: 2021/11/26 13:18:42 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	t;

	if (!little[0])
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		t = 0;
		if (big[i] == little[0])
		{
			j = 1;
			t = i + 1;
			while ((big[t] == little[j]) && little[j] && (t < len))
			{
				t++;
				j++;
			}
			if (!little[j])
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
