/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:04:48 by ldubuche          #+#    #+#             */
/*   Updated: 2022/09/28 14:06:19 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	free_split_return_1(char **split)
{
	free_split(split);
	return (1);
}

int	check_rgb(char *rgb)
{
	int		i;
	char	**split_rgb;

	i = 0;
	split_rgb = ft_split(rgb, ',');
	if (!split_rgb)
		return (1);
	while (split_rgb[i] != NULL)
		i++;
	if (i != 3)
		return (free_split_return_1(split_rgb));
	while (--i >= 0)
	{
		if (strisint8(split_rgb[i]))
			return (free_split_return_1(split_rgb));
		if (ft_atoi(split_rgb[i]) > 255)
			return (free_split_return_1(split_rgb));
	}
	free_split(split_rgb);
	return (0);
}

int	texture_line(char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (-1);
	if (split_line[0] && (ft_strncmp(split_line[0], "NO", 3)
			&& ft_strncmp(split_line[0], "SO", 3)
			&& ft_strncmp(split_line[0], "WE", 3)
			&& ft_strncmp(split_line[0], "EA", 3)
			&& ft_strncmp(split_line[0], "F", 3)
			&& ft_strncmp(split_line[0], "C", 3)))
		return (free_split_return_1(split_line));
	if (ft_strncmp(split_line[0], "c", 2) == 0
		|| ft_strncmp(split_line[0], "F", 2) == 0)
	{
		if (check_rgb(split_line[1]))
			return (free_split_return_1(split_line));
	}
	if (split_line[2] != NULL)
		return (free_split_return_1(split_line));
	free_split(split_line);
	return (0);
}

int	transform_rgb(char *rgb_color)
{
	char	**split_rgb;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	split_rgb = ft_split(rgb_color, ',');
	if (!split_rgb)
		return (-1);
	red = (uint8_t) ft_atoi(split_rgb[0]);
	green = (uint8_t) ft_atoi(split_rgb[1]);
	blue = (uint8_t) ft_atoi(split_rgb[2]);
	free_split(split_rgb);
	return (red << 16 | green << 8 | blue);
}

void	stock_texture(char *line, t_map **map)
{
	char	**split_line;
	char	**split_temp;

	split_temp = ft_split(line, ' ');
	split_line = ft_split(split_temp[1], '\n');
	if (!split_line)
		return ;
	if (!ft_strncmp(split_temp[0], "NO", 3))
		(*map)->texture->no_texture = ft_strdup(split_line[0]);
	else if (!ft_strncmp(split_temp[0], "SO", 3))
		(*map)->texture->so_texture = ft_strdup(split_line[0]);
	else if (!ft_strncmp(split_temp[0], "WE", 3))
		(*map)->texture->we_texture = ft_strdup(split_line[0]);
	else if (!ft_strncmp(split_temp[0], "EA", 3))
		(*map)->texture->ea_texture = ft_strdup(split_line[0]);
	else if (!ft_strncmp(split_temp[0], "F", 2))
		(*map)->texture->floor_rgb = transform_rgb(split_line[0]);
	else if (!ft_strncmp(split_temp[0], "C", 2))
		(*map)->texture->ceiling_rgb = transform_rgb(split_line[0]);
	free_split(split_temp);
	free_split(split_line);
}
