/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 15:08:39 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <math.h>

int	move_dir(t_core *core, int keycode)
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
	if (create_img(core, &core->main_img, WIN_WIDTH, WIN_HEIGHT) == FAILED)
		return (FAILED);
	raycasting(core);
	mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
	if (core->mini_map.img)
	{
		if (create_img(core, &core->mini_map, W_MINIMAP, H_MINIMAP) == FAILED)
			return (FAILED);
		draw_minimap(core);
		mlx_put_image_to_window(core->mlx, core->win, core->mini_map.img, 0, 0);
	}
	return (SUCCESS);
}

