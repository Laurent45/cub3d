/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:10:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 14:53:27 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include <math.h>

void	init_player(t_player *player)
{
	player->pos.x = PLAYER_X;
	player->pos.y = PLAYER_Y;
	player->view.angle = SOUTH;
	update_view(player);
	player->f_front = 0.0;
	player->f_side = 0.0;
}

void	update_view(t_player *player)
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
		player->pos.x += (player->view.v_front.x * player->f_front);
		player->pos.x += (player->view.v_side.x * player->f_side);
		player->pos.y += (player->view.v_front.y * player->f_front);
		player->pos.y += (player->view.v_side.y * player->f_side);
		player->f_side = 0.0;
		player->f_front = 0.0;
}
