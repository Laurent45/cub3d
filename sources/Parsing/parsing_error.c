/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:38:56 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 15:41:35 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_map	*p_error(t_error type, char *cub_file)
{
	ft_putstr_fd("Error\n", 2);
	if (type == ERR_ARG_NBR)
		ft_putstr_fd("./cub3d file.cub\n", 2);
	else if (type == ERR_EMPTY_ENV)
		ft_putstr_fd("Environnement is empty\n", 2);
	else if (type == ERR_VALID_NAME)
	{
		ft_putstr_fd(cub_file, 2);
		ft_putstr_fd(" : not a valid name\n", 2);
	}
	else if (type == ERR_VALID_FILE)
	{
		ft_putstr_fd(cub_file, 2);
		ft_putstr_fd(" : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	else if (type == ERR_NOT_VALID_LINE)
		ft_putstr_fd("Invalid line found in the file\n", 2);
	else if (type == ERR_MISSING_INFO)
		ft_putstr_fd("Invalid file : missing information\n", 2);
	return (NULL);
}

int	*p_error_map(t_error type, int *tab)
{
	ft_putstr_fd("Error\n", 2);
	if (type == ERR_MTPL_CHARA)
	{
		free(tab);
		ft_putstr_fd("Invalid map : multiple character detected\n", 2);
	}
	else if (type == ERR_WRONG_CHARA)
	{
		free(tab);
		ft_putstr_fd("Invalid map : map must contain only 0, 1 , N, \
		S, E ,W\n", 2);
	}
	else if (type == ERR_NOT_VALID_LINE)
		ft_putstr_fd("Invalid line found in the file\n", 2);
	return (NULL);
}

int	p_error_int(t_error type, t_map *map, int fd, char *line)
{
	ft_putstr_fd("Error\n", 2);
	close(fd);
	if (type == ERR_MALLOC)
		ft_putstr_fd("Memory allocation fail\n", 2);
	else
		free_map(map, 0);
	if (type == ERR_EMPTY_FILE)
		ft_putstr_fd("File is empty\n", 2);
	else if (type == ERR_NOT_VALID_LINE)
	{
		ft_putstr_fd("Invalid line : ", 2);
		ft_putstr_fd(line, 2);
	}
	else if (type == ERR_MISSING_INFO)
		ft_putstr_fd("Invalid file : missing information\n", 2);
	else if (type == ERR_MISSING_MAP)
		ft_putstr_fd("Invalid file : missing map\n", 2);
	else if (type == ERR_MALLOC_2)
		ft_putstr_fd("Memory allocation fail\n", 2);
	else if (type == ERR_MAP)
		ft_putstr_fd("Map is not in a valid format\n", 2);
	if (line)
		free(line);
	return (1);
}
