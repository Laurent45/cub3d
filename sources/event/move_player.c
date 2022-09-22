/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:43:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "init.h"
#include "draw.h"
#include "mlx.h"

int	move_player(t_core *core, int keycode)
{
	t_player	*player;
	t_img_info	*img;
	t_point		pos;

	player = &core->player;
	img = &core->main_img;
	set_values(&pos, player->pos.x, player->pos.y);

	if (keycode == KEY_W)
		player->f_front += PLAYER_SPEED; 
	if (keycode == KEY_S)
		player->f_front -= PLAYER_SPEED; 
	if (keycode == KEY_A)
		player->f_side -= PLAYER_SPEED; 
	if (keycode == KEY_D)
		player->f_side += PLAYER_SPEED; 
	pos.x += (player->view.v_front.x * player->f_front) + (player->view.v_side.x * player->f_side);
	pos.y += (player->view.v_front.y * player->f_front) + (player->view.v_side.y * player->f_side);

	if (img->img)
		mlx_destroy_image(core->mlx, img->img);
	img->img = mlx_new_image(core->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	draw_map(img);	
	draw_player(pos, player, img);	
	mlx_put_image_to_window(core->mlx, core->win, img->img, 0, 0);
	return (SUCCESS);
}
