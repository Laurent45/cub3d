/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 11:06:36 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <math.h>

static int in_wall(t_map *map, t_pos *pos)
{
	if (map->map[(int) pos->y][(int) pos->x] == 0)
		return (0);
	return (1);
}

void	move_player(t_core *core, int keycode)
{
	t_player	*player;
	int			tmp_f;
	int			tmp_s;

	player = &core->player;
	tmp_f = player->f_front;
	tmp_s = player->f_side;
	if (keycode == KEY_W)
		player->f_front += VELOCITY; 
	if (keycode == KEY_S)
		player->f_front -= VELOCITY; 
	if (keycode == KEY_A)
		player->f_side -= VELOCITY; 
	if (keycode == KEY_D)
		player->f_side += VELOCITY; 
	player->pos.x = player->pos_tmp.x;
	player->pos.x += 0.1 * cos(to_rad(player->dir)) * player->f_front; 
	player->pos.x += 0.1 * cos(to_rad(set_angle(player->dir + 90.0))) * player->f_side;
	player->pos.y = player->pos_tmp.y;
	player->pos.y += 0.1 * sin(to_rad(player->dir)) * player->f_front; 
	player->pos.y += 0.1 * sin(to_rad(set_angle(player->dir + 90.0))) * player->f_side;
	if (in_wall(core->map, &player->pos))
	{
		player->f_side = tmp_s;
		player->f_front = tmp_f;
		player->pos.x = player->pos_tmp.x;
		player->pos.x += 0.1 * cos(to_rad(player->dir)) * player->f_front; 
		player->pos.x += 0.1 * cos(to_rad(set_angle(player->dir + 90.0))) * player->f_side;
		player->pos.y = player->pos_tmp.y;
		player->pos.y += 0.1 * sin(to_rad(player->dir)) * player->f_front; 
		player->pos.y += 0.1 * sin(to_rad(set_angle(player->dir + 90.0))) * player->f_side;
	}
	create_img(core, &core->main_img, WIN_WIDTH, WIN_HEIGHT);
	/* draw_map(&core->main_img, core->map); */
	draw_player(core);
	mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
}
