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

/* Voir pour remplacer avec un enum */
t_map	*p_error(t_error type, char *cub_file, int fd)
{
	printf("Error\n");
	if (type == ERR_ARG_NBR)
		printf("./cub3d file.cub\n");
	else if (type == ERR_EMPTY_ENV)
		printf("Environnement is empty\n");
	else if (type == ERR_VALID_NAME)
		printf("%s : not a valid name\n", cub_file);
	else if (type == ERR_VALID_FILE)
	{
		close(fd);
		printf("%s : %s\n", cub_file, strerror(errno));
	}
	else if (type == ERR_NOT_VALID_LINE)
		printf("Invalid line found in the file\n");
	else if (type == ERR_MISSING_INFO)
		printf("Invalid file : missing information\n");
	return (NULL);
}

int	*p_error_map(t_error type, int *tab)
{
	printf("Error\n");
	if (type == ERR_MTPL_CHARA)
	{
		free(tab);
		printf("Invalid map : multiple character detected\n");
	}
	else if (type == ERR_WRONG_CHARA)
	{
		free(tab);
		printf("Invalid map : map must contain only 0, 1 , N, S, E ,W\n");
	}
	else if (type == ERR_NOT_VALID_LINE)
		printf("Invalid line found in the file\n");
	return (NULL);
}

int	p_error_int(t_error type, t_map *map, int fd, char *line)
{
	printf("Error\n");
	close(fd);
	if (type == ERR_MALLOC)
		printf("Memory allocation fail\n");
	else
		free_map(map, -1);
	if (type == ERR_EMPTY_FILE)
		printf("File is empty\n");
	else if (type == ERR_NOT_VALID_LINE)
	{
		printf("Invalid line : %s", line);
		free(line);
	}
	else if (type == ERR_MISSING_INFO)
		printf("Invalid file : missing information\n");
	else if (type == ERR_MISSING_MAP)
		printf("Invalid file : missing map\n");
	else if (type == ERR_MALLOC_2)
		printf("Memory allocation fail\n");
	return (1);
}
