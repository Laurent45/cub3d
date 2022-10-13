/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:30:04 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 20:33:16 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

static void	draw_player(t_core *core)
{
	t_rect		rect;
	t_player	*player;
	t_pos		dir;
	t_point		a;

	player = &core->player;
	pixel_point(&rect.center, &player->pos, core, &core->mini_map);
	rect.l_height = 5;
	rect.l_width = 5;
	rect.color = 0x000000;
	draw_rect_fill(&rect, &core->mini_map);
	dir.x = player->pos.x + 1 * cos(to_rad(set_angle(player->dir)));
	dir.y = player->pos.y + 1 * sin(to_rad(set_angle(player->dir)));
	pixel_point(&a, &dir, core, &core->mini_map);
	draw_segment(rect.center, a, 0xFF0000, &core->mini_map);
}

static void	draw_map(t_img_info *img, t_map *map)
{
	t_rect	rect;
	int		y;
	int		x;
	double	x_incr;
	double	y_incr;

	x_incr = (double) img->width / map->width;
	y_incr = (double) img->height / map->height;
	rect.l_height = y_incr;
	rect.l_width = x_incr;
	y = 0;
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			rect.center.x = round(x * x_incr + (x_incr / 2.0));
			rect.center.y = round(y * y_incr + (y_incr / 2.0));
			rect.color = 0x003300;
			if (map->map[y][x] == 0 || map->map[y][x] == 2)
				rect.color = 0xFFFFFF;
			draw_rect_fill(&rect, img);
		}
		y++;
	}
}

void	draw_minimap(t_core *core)
{
	draw_map(&core->mini_map, core->map);
	draw_player(core);
}
