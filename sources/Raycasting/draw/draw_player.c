/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:44:18 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 17:02:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"

#include <math.h>
#include <stdio.h>

void	draw_player(t_img_info *img, t_player *player, t_map *map)
{
	t_rect	rect;
	t_point	dir;
	
	rect.center.x = round(player->pos_x * (WIN_WIDTH / map->width));
	rect.center.y = round(player->pos_y * (WIN_HEIGHT / map->height));
	rect.l_height = 10;
	rect.l_width = 10;
	rect.color = 0x08C2F3;
	draw_rect_fill(&rect, img);
	dir.x = round(rect.center.x + 15 * cos(to_rad(player->dir)));
	dir.y = round(rect.center.y + 15 * sin(to_rad(player->dir)));
	draw_segment(rect.center, dir, 0x000000, img);
	
}
