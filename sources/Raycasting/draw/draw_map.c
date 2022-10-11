/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:30:04 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 15:42:31 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"

#include <math.h>

void	draw_map(t_img_info *img, t_map *map)
{
	t_rect	rect;
	int		y;
	int		x;
	double	x_incr;
	double	y_incr;
	
	x_incr = (double) img->width / (map->width);
	y_incr = (double) img->height / (map->height);
	rect.l_height = y_incr;
	rect.l_width = x_incr;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			rect.center.x = round(x * x_incr + (x_incr / 2.0));
			rect.center.y = round(y * y_incr + (y_incr / 2.0));
			if (map->map[y][x] == 0 || map->map[y][x] == 2)
				rect.color = 0xFFFFFF;
			else if (map->map[y][x] == 3)
				rect.color = 0x33AA12;
			else
				rect.color = 0x003300;
			draw_rect_fill(&rect, img);
			rect.color = 0x000000;
			draw_rect(&rect, img);
			x++;
		}
		y++;
	}
}
