/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:01:30 by lfrederi          #+#    #+#             */
/*   Updated: 2022/04/14 14:48:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_stdio.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_sizetocpy(char *buf)
{
	size_t	ret;

	ret = 0;
	while (buf[ret] && (buf[ret] != '\n'))
		ret++;
	if (buf[ret] == '\n')
		ret++;
	return (ret);
}

size_t	ft_strlen_gnl(char *buf)
{
	size_t	len;

	if (!buf)
		return (0);
	len = 0;
	while (buf[len])
		len++;
	return (len);
}

void	ft_strlcat_gnl(char *dest, char *src, size_t lencopy)
{
	size_t	i;
	size_t	j;

	if (!src)
		return ;
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < lencopy)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
}

void	ft_managebuffer(char *buf, size_t lenbuffer, size_t lencopy)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = lencopy;
	while (i < lenbuffer)
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	while (j <= lenbuffer)
	{
		buf[j] = 0;
		j++;
	}
}

char	*ft_getbuffer(t_buffd *buffd, int fd)
{
	int	i;

	i = 0;
	while ((i < FD_MAX) && (buffd[i].fd != 0))
	{
		if (buffd[i].fd == fd)
			return (buffd[i].buf);
		i++;
	}
	if (i < FD_MAX)
	{
		buffd[i].fd = fd;
		return (buffd[i].buf);
	}
	return (NULL);
}
