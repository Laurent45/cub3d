/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:04:20 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/28 16:30:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "player.h"
#include "image.h"
#include "utils.h"

int	move_player(t_core *core, int keycode)
{
	t_player	*player;

	player = &core->player;
	if (keycode == KEY_W)
		player->f_front += PLAYER_SPEED; 
	if (keycode == KEY_S)
		player->f_front -= PLAYER_SPEED; 
	if (keycode == KEY_A)
		player->f_side -= PLAYER_SPEED; 
	if (keycode == KEY_D)
		player->f_side += PLAYER_SPEED; 
	update_pos(player);
	main_img(core);
	return (SUCCESS);
}
