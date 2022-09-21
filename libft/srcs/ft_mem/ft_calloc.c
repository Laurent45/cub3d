/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:12:38 by lfrederi          #+#    #+#             */
/*   Updated: 2021/12/23 15:51:55 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_mem.h"
#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, (size * count));
	return (ret);
}
