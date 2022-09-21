/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:07:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 13:45:02 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_string.h"
#include "../../headers/ft_mem.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	len_s;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= (unsigned int) len_s)
		return ((char *) ft_calloc(1, 1));
	size = len_s - start;
	if (size < len)
		len = size;
	ret = (char *) ft_calloc((len + 1), 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	return (ret);
}
