/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 19:58:21 by lfrederi         ###   ########.fr       */
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
	main_img(core);
	return (SUCCESS);
}
