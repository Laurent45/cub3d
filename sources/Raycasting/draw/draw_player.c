/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:44:18 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 17:33:43 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"

#include <math.h>
#include <stdio.h>

void	draw_player(t_core *core)
{
	t_rect		rect;
	t_player	*player;
	t_raycast	raycast;
	t_pos		dir;
	t_point		a;

	player = &core->player;
	pixel_point(&rect.center, &player->pos, core);
	rect.l_height = 10;
	rect.l_width = 10;
	rect.color = 0x08C2F3;
	draw_rect_fill(&rect, &core->main_img);
	double i = 0;
	double fov = -(FOV / 2.0);
	while (i < FOV)
	{
		dir.x = player->pos.x + 1 * cos(to_rad(set_angle(player->dir + fov)));
		dir.y = player->pos.y + 1 * sin(to_rad(set_angle(player->dir + fov)));
		pixel_point(&a, &dir, core);
		draw_segment(rect.center, a, 0x000000, &core->main_img);
		fov++;
		i++;
	}
	double j = FOV / WIN_WIDTH;
	double ray = set_angle(player->dir - (FOV / 2));
	i = 0;
	while (i < WIN_WIDTH)
	{
		horizontal_intersec(core, ray, &raycast);
		if (raycast.horizontal.x != 0)
		{
			t_point b;
			pixel_point(&b, &raycast.horizontal, core);
			draw_segment(rect.center, b, 0x1B65CC, &core->main_img);
		}
		vertical_intersec(core, ray, &raycast);
		if (raycast.vertical.x != 0)
		{
			t_point b;
			pixel_point(&b, &raycast.vertical, core);
			draw_segment(rect.center, b, 0x34B2A8, &core->main_img);
		}
		ray = set_angle(ray + j);
		i++;
	}

}
