/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 20:58:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <math.h>


void	move_dir(t_core *core, int keycode)
{
	t_player	*player;

	player = &core->player;
	if (player->f_front != 0.0 || player->f_side != 0.0)
	{
		player->pos_tmp.x = player->pos.x;
		player->pos_tmp.y = player->pos.y;
		player->f_side = 0.0;
		player->f_front = 0.0;
	}
	if (keycode == ARROW_LEFT)
		player->dir = set_angle(player->dir - DIR_INCR);
	if (keycode == ARROW_RIGHT)
		player->dir = set_angle(player->dir + DIR_INCR);
	init_main_img(core, WIN_WIDTH, WIN_HEIGHT);
	draw_map(&core->main_img, core->map);
	draw_player(core);
	mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
}

