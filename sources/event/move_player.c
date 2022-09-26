/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 12:13:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "player.h"
#include "image.h"
#include "utils.h"

int	move_player(t_core *core, int keycode)
{
	t_player	*player;
	t_point		pos;

	player = &core->player;
	set_values(&pos, player->pos.x, player->pos.y);
	if (keycode == KEY_W)
		player->f_front += PLAYER_SPEED; 
	if (keycode == KEY_S)
		player->f_front -= PLAYER_SPEED; 
	if (keycode == KEY_A)
		player->f_side -= PLAYER_SPEED; 
	if (keycode == KEY_D)
		player->f_side += PLAYER_SPEED; 
	pos.x += (player->view.v_front.x * player->f_front);
	pos.x += (player->view.v_side.x * player->f_side);
	pos.y += (player->view.v_front.y * player->f_front);
	pos.y += (player->view.v_side.y * player->f_side);
	img_move_player(core, pos);
	return (SUCCESS);
}
