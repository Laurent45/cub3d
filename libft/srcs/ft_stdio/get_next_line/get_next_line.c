/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:44:32 by lfrederi          #+#    #+#             */
/*   Updated: 2022/04/14 14:48:10 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../../headers/ft_stdio.h"

char	*ft_createline(int fd, char *curr)
{
	static t_buffd	buffd[FD_MAX + 1];
	char			*buf;
	size_t			size_copy;
	size_t			lencurr;
	char			*ret;

	buf = ft_getbuffer(buffd, fd);
	if (!buf)
		return (NULL);
	if (!ft_strlen_gnl(buf))
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL);
	size_copy = ft_sizetocpy(buf);
	lencurr = ft_strlen_gnl(curr);
	ret = (char *) malloc(sizeof(char) * (lencurr + size_copy + 1));
	if (!ret)
		return (NULL);
	ret[0] = 0;
	ft_strlcat_gnl(ret, curr, lencurr);
	if (curr)
		free(curr);
	ft_strlcat_gnl(ret, buf, size_copy);
	ft_managebuffer(buf, ft_strlen_gnl(buf), size_copy);
	return (ret);
}

int	ft_isnewline(char *str)
{
	return (str[ft_strlen_gnl(str) - 1] == '\n');
}

char	*get_next_line(int fd)
{
	char	*next_line;
	char	*tmp;

	if (fd < 0)
		return (NULL);
	next_line = NULL;
	tmp = NULL;
	next_line = ft_createline(fd, next_line);
	if (!next_line)
		return (NULL);
	while (!ft_isnewline(next_line))
	{
		tmp = next_line;
		next_line = ft_createline(fd, next_line);
		if (!next_line)
			return (tmp);
	}
	return (next_line);
}
