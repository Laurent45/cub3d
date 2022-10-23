/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:09:40 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 14:24:19 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_map	*alloc_map(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map) * 1);
	if (!map)
		return (NULL);
	map->direction = NO_DIRECTION;
	map->height = 0;
	map->width = 0;
	map->texture = (t_texture *) malloc(sizeof(t_texture) * 1);
	if (!map->texture)
	{
		free(map);
		return (NULL);
	}
	map->texture->no_texture = NULL;
	map->texture->so_texture = NULL;
	map->texture->we_texture = NULL;
	map->texture->ea_texture = NULL;
	map->texture->floor_rgb = -1;
	map->texture->ceiling_rgb = -1;
	map->map = NULL;
	return (map);
}

int	valid_map(int fd, t_map **map)
{
	char	*line;

	*map = alloc_map();
	if (!*map)
		return (p_error_int(ERR_MALLOC, NULL, fd, NULL));
	line = get_next_line(fd);
	if (!line)
		return (p_error_int(ERR_EMPTY_FILE, *map, fd, NULL));
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
			line = next_line(fd, line);
		else if (texture_line(line) == 0)
		{
			stock_texture(line, map);
			line = next_line(fd, line);
		}
		else if (map_line(line, 0, fd) == 0)
			break ;
		else
			return (p_error_int(ERR_NOT_VALID_LINE, *map, fd, line));
	}
	if (read_map(fd, line, map))
		return (1);
	return (0);
}
