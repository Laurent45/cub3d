/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:44:12 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "init.h"
#include "draw.h"
#include "mlx.h"

#include <math.h>

void	move_dir_view(t_core *core, int keycode)
{
	t_player	*player;
	t_img_info	*img;

	player = &core->player;
	img = &core->main_img;
	// Update pos
	if (player->f_front != 0.0 || player->f_side != 0.0)
	{
		player->pos.x += (player->view.v_front.x * player->f_front) + (player->view.v_side.x * player->f_side);
		player->pos.y += (player->view.v_front.y * player->f_front) + (player->view.v_side.y * player->f_side);
		player->f_side = 0.0;
		player->f_front = 0.0;
	}

	if (keycode == ARROW_LEFT)
		player->view.angle -= VIEW_INCR;
	if (keycode == ARROW_RIGHT)
		player->view.angle += VIEW_INCR;
	if (player->view.angle > MAX_RADIAN)
		player->view.angle -= MAX_RADIAN;
	if (player->view.angle <= 0.0)
		player->view.angle = MAX_RADIAN + player->view.angle;

	player->view.v_front.x = (int) ceil(VIEW_SIZE * cos(player->view.angle));
	player->view.v_front.y = (int) ceil(VIEW_SIZE * sin(player->view.angle));
	player->view.v_side.x = (int) ceil(VIEW_SIZE * cos(player->view.angle + R_45));
	player->view.v_side.y = (int) ceil(VIEW_SIZE * sin(player->view.angle + R_45));

	if (img->img)
		mlx_destroy_image(core->mlx, img->img);
	img->img = mlx_new_image(core->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	draw_map(img);	
	draw_player(player->pos, player, img);	
	mlx_put_image_to_window(core->mlx, core->win, img->img, 0, 0);
}
