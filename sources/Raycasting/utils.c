/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:58:27 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 16:28:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	set_angle(double angle)
{
	if (angle < 0.0)
		return (360.0 + angle);
	if (angle >= 360.0)
		return (angle - 360.0);
	return (angle);
}

double	to_rad(double angle)
{
	return ((angle * M_PI) / 180.0);
}

int	is_wall(t_map *map, t_pos *a)
{
	if (map->map[(int) (a->y)][(int) (a->x)] == 0)
		return (0);
	return (1);
}

void	put_pixel_img(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x >= WIN_WIDTH) || (y < 0 || y >= WIN_HEIGHT))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	set_position(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}
