/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 07:41:43 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

static void	reset_pos(t_player *player)
{
	(void) player;
}

void	move_dir(t_core *core, int keycode)
{
	t_player	*player;

	player = &core->player;
	if (player->f_front != 0.0 || player->f_side != 0.0)
		reset_pos(player);
	if (keycode == ARROW_LEFT)
		player->dir = set_angle(player->dir - DIR_INCR);
	if (keycode == ARROW_RIGHT)
		player->dir = set_angle(player->dir + DIR_INCR);
	/* update_view_vector(player); */
	init_main_img(core, WIN_WIDTH, WIN_HEIGHT);
	draw_map(&core->main_img, core->map);
	draw_player(&core->main_img, &core->player, core->map);
	mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
}

