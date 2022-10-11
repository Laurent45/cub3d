/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 20:58:12 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <math.h>

void	move_player(t_core *core, int keycode)
{
	t_player	*player;

	player = &core->player;
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
	init_main_img(core, WIN_WIDTH, WIN_HEIGHT);
	draw_map(&core->main_img, core->map);
	draw_player(core);
	mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
}
