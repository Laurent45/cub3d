/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:10:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/06 08:56:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "init.h"
#include <math.h>

void	init_player(t_player *player)
{
	player->map_pos.x = PLAYER_X;
	player->map_pos.y = PLAYER_Y;
	player->pos.x = PLAYER_X * SIZE_CUBE + SIZE_CUBE / 2;
	player->pos.y = PLAYER_Y * SIZE_CUBE + SIZE_CUBE / 2;
	player->tmp_pos.x = player->pos.x;
	player->tmp_pos.y = player->pos.y;
	player->view.angle = PLAYER_DIR;
	update_view_vector(player);
	player->f_front = 0.0;
	player->f_side = 0.0;
}

void	update_view_vector(t_player *player)
{
	t_view	*view;

	view = &player->view;
	view->v_front.x = (int) round(VIEW_SIZE * cos(player->view.angle * RAD));
	view->v_front.y = (int) round(VIEW_SIZE * sin(player->view.angle * RAD));
	view->v_side.x = (int) round(VIEW_SIZE * cos((player->view.angle + 90) * RAD));
	view->v_side.y = (int) round(VIEW_SIZE * sin((player->view.angle + 90) * RAD));
}

void	update_pos(t_player *player)
{
		player->pos.x = player->tmp_pos.x;
		player->pos.x += (player->view.v_front.x * player->f_front);
		player->pos.x += (player->view.v_side.x * player->f_side);
		player->pos.y = player->tmp_pos.y;
		player->pos.y += (player->view.v_front.y * player->f_front);
		player->pos.y += (player->view.v_side.y * player->f_side);
}

void	reset_pos(t_player *player)
{
		player->tmp_pos.x = player->pos.x;
		player->tmp_pos.y = player->pos.y;
		player->f_side = 0.0;
		player->f_front = 0.0;
}
