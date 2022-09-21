/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:52:57 by lfrederi          #+#    #+#             */
/*   Updated: 2021/11/29 14:57:22 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	*tmp;

	if (s)
	{
		tmp = s;
		while (*tmp)
		{
			write(fd, tmp, 1);
			tmp++;
		}
	}
	write(fd, "\n", 1);
}
