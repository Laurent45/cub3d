/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:00:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/14 11:18:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

void	put_pixel_img(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x >= img->width) || (y < 0 || y >= img->height))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	is_wall(t_map *map, t_pos *a, int dir)
{
	int	wall;

	if (floor(a->x) <= 0.0 || floor(a->y) <= 0.0)
		return (1);
	if (dir == NORTH)
		wall = map->map[(int) floor(a->y - 1)][(int) floor(a->x)];
	if (dir == SOUTH)
		wall = map->map[(int) floor(a->y)][(int) floor(a->x)];
	if (dir == EAST)
		wall = map->map[(int) floor(a->y)][(int) floor(a->x)];
	if (dir == WEST)
		wall = map->map[(int) floor(a->y)][(int) floor(a->x - 1)];
	if (wall == 0 || wall == 2)
		return (0);
	return (1);
}

int	in_wall(t_map *map, t_pos *pos)
{
	t_pos	tmp;
	double	angle;

	angle = 0.0;
	while (angle < 360)
	{
		tmp.x = pos->x + 0.1 * cos(to_rad(angle));
		tmp.y = pos->y + 0.1 * sin(to_rad(angle));
		if (floor(tmp.x) <= 0.0 || floor(tmp.y) <= 0.0)
			return (1);
		if ((map->map[(int) tmp.y][(int) tmp.x] != 0) \
			&& (map->map[(int) tmp.y][(int) tmp.x] != 2))
			return (1);
		angle++;
	}
	return (0);
}

void	set_position(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}
