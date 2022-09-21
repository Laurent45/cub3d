/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:24:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 13:46:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../headers/ft_string.h"

static int	ft_isset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_lentrim(char const *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[start], set))
		start++;
	if (!s1[start])
		return (0);
	while (ft_isset(s1[end], set))
		end--;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (!s1)
		return (NULL);
	if (set)
	{
		start = 0;
		len = ft_lentrim(s1, set);
		while (ft_isset(s1[start], set))
			start++;
		return (ft_substr(s1, start, len));
	}
	else
		return (ft_strdup(s1));
}
