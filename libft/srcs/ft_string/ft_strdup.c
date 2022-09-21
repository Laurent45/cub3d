/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:47:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/01/07 13:43:32 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_string.h"
#include "../../headers/ft_mem.h"

char	*ft_strdup(const char *s1)
{
	void	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = ft_calloc((len + 1), 1);
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s1, len);
	return ((char *) dup);
}
