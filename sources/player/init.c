/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:10:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 15:13:35 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <math.h>

void	init_player(t_player *player)
{
	player->pos.x = PLAYER_X;
	player->pos.y = PLAYER_Y;
	player->pos_tmp.x = PLAYER_X;
	player->pos_tmp.y = PLAYER_Y;
	player->view.angle = PLAYER_DIR;
	update_view_vector(player);
	player->f_front = 0.0;
	player->f_side = 0.0;
}

void	update_view_vector(t_player *player)
{
	t_view	*view;

	view = &player->view;
	view->v_front.x = (int) round(VIEW_SIZE * cos(player->view.angle));
	view->v_front.y = (int) round(VIEW_SIZE * sin(player->view.angle));
	view->v_side.x = (int) round(VIEW_SIZE * cos(player->view.angle + PI / 2));
	view->v_side.y = (int) round(VIEW_SIZE * sin(player->view.angle + PI / 2));
}

void	update_pos(t_player *player)
{
		player->pos.x = player->pos_tmp.x;
		player->pos.x += (player->view.v_front.x * player->f_front);
		player->pos.x += (player->view.v_side.x * player->f_side);
		player->pos.y = player->pos_tmp.y;
		player->pos.y += (player->view.v_front.y * player->f_front);
		player->pos.y += (player->view.v_side.y * player->f_side);
}

void	reset_pos(t_player *player)
{
		player->pos_tmp.x = player->pos.x;
		player->pos_tmp.y = player->pos.y;
		player->f_side = 0.0;
		player->f_front = 0.0;
}
