/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:16:06 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 13:45:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../headers/ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_join;
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 | !s2)
		return (NULL);
	len_join = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) malloc(sizeof(char) * (len_join + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		join[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	return (join);
}
