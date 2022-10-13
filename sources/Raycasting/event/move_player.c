/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 20:45:22 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"
#include <math.h>

static void	update_pos(t_player *player)
{
	player->pos.x = player->pos_tmp.x;
	player->pos.x += 0.1 * cos(to_rad(player->dir)) * player->f_front;
	player->pos.x += 0.1 * cos(to_rad(set_angle(player->dir + 90.0))) \
						* player->f_side;
	player->pos.y = player->pos_tmp.y;
	player->pos.y += 0.1 * sin(to_rad(player->dir)) * player->f_front;
	player->pos.y += 0.1 * sin(to_rad(set_angle(player->dir + 90.0))) \
						* player->f_side;
}

static int	re_draw(t_core *core)
{
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

int	move_player(t_core *core, int keycode)
{
	int			tmp_f;
	int			tmp_s;

	tmp_f = core->player.f_front;
	tmp_s = core->player.f_side;
	if (keycode == KEY_W)
		core->player.f_front += VELOCITY;
	if (keycode == KEY_S)
		core->player.f_front -= VELOCITY;
	if (keycode == KEY_A)
		core->player.f_side -= VELOCITY;
	if (keycode == KEY_D)
		core->player.f_side += VELOCITY;
	update_pos(&core->player);
	if (in_wall(core->map, &core->player.pos))
	{
		core->player.f_side = tmp_s;
		core->player.f_front = tmp_f;
		update_pos(&core->player);
		return (SUCCESS);
	}
	return (re_draw(core));
}
