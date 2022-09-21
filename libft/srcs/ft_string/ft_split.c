/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:46:35 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 13:47:19 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../headers/ft_string.h"

static size_t	ft_lensplit(char const *s, char c)
{
	size_t	i;
	size_t	lensplit;

	i = 0;
	lensplit = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		lensplit++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (lensplit);
}

static char	**ft_clear(char **split, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_checksplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return ((char **) malloc(sizeof(char *) * (ft_lensplit(s, c) + 1)));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	start;
	size_t	end;

	split = ft_checksplit(s, c);
	if (!split)
		return (NULL);
	i = -1;
	end = 0;
	while (++i < ft_lensplit(s, c))
	{
		start = end;
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_substr(s, (unsigned int) start, (end - start));
		if (!split[i])
			return (ft_clear(split, i));
	}
	split[i] = NULL;
	return (split);
}
