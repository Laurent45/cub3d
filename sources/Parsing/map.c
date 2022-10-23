/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:14:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/10/11 16:37:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_direction	which_direction(char c, t_map *map, int x, int y)
{
	map->posx = x;
	map->posy = y;
	if (c == 'N')
		return (DIR_NORTH);
	else if (c == 'S')
		return (DIR_SOUTH);
	else if (c == 'E')
		return (DIR_EAST);
	else if (c == 'W')
		return (DIR_WEST);
	return (NO_DIRECTION);
}

int	*char_to_int(char *li, t_map *map, int i, int y)
{
	int	*tab_line;

	tab_line = (int *) malloc(sizeof(int) * (map->width + 1));
	if (!tab_line)
		return (NULL);
	while (li[++i] && li[i] != '\n')
	{
		if (li[i] == ' ')
			tab_line[i] = 3;
		else if (li[i] == '0' || li[i] == '1')
			tab_line[i] = li[i] - 48;
		else if (li[i] == 'N' || li[i] == 'E' || li[i] == 'W' || li[i] == 'S')
		{
			tab_line[i] = 2;
			if (map->direction != NO_DIRECTION)
				return (p_error_map(ERR_MTPL_CHARA, tab_line));
			else
				map->direction = which_direction(li[i], map, i, y);
		}
		else
			return (p_error_map(ERR_WRONG_CHARA, tab_line));
	}
	while (i < map->width)
		tab_line[i++] = 3;
	return (tab_line);
}

int	map_line(char *line, int j, int fd)
{
	int	i;

	i = 0;
	if (ft_strncmp(line, "\n", 2) == 0)
		return (p_error_int(ERR_NOT_VALID_LINE, NULL, fd, NULL));
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'E'\
			&& line[i] != 'W' && line[i] != 'S' && line[i] != ' ' \
			&& line[i] != '\n')
		{
			if (j == 1)
			{
				ft_putstr_fd("Error\nWrong character ", 2);
				ft_putchar_fd(line[i], 2);
				ft_putstr_fd("\n", 2);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	**rec_read_map(int fd, int i, t_map **map)
{
	int		**tab;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		tab = (int **) malloc(sizeof(int *) * (i + 1));
		if (!tab)
			return (NULL);
		(*map)->height = i;
		tab[i] = NULL;
		return (tab);
	}
	else if (map_line(line, 1, fd))
		return (free_line(line, NULL, 0, (*map)->height));
	else
	{
		(*map)->width = compare(ft_strlen(line), (*map)->width);
		tab = rec_read_map(fd, i + 1, map);
		if (tab)
			tab[i] = char_to_int(line, *map, -1, i);
		if (!tab || !tab[i])
			return (free_line(line, tab, i, (*map)->height));
		return (free_line(line, tab, 0, (*map)->height));
	}
}

int	read_map(int fd, char *line, t_map **map)
{
	if (!line)
		return (p_error_int(ERR_MISSING_MAP, *map, fd, NULL));
	(*map)->map = rec_read_map(fd, 1, map);
	if (!(*map)->map)
	{
		free(line);
		free_map(*map, 0);
		return (1);
	}
	(*map)->map[0] = char_to_int(line, *map, -1, 0);
	if ((*map)->map[0] == NULL)
		return (p_error_int(ERR_MALLOC_2, *map, fd, line));
	if (valid_walls(*map))
		return (p_error_int(ERR_MAP, *map, fd, line));
	free(line);
	return (0);
}
