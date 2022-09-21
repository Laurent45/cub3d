/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:57:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 19:48:42 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "init.h"

#include <math.h>
#include <stdio.h>

static void	draw_dir_view(t_player *player, t_img_info *img)
{
	t_point	dir_vector;

	dir_vector.x = player->pos.x + player->dir_view.x;
	dir_vector.y = player->pos.y + player->dir_view.y;
	draw_segment(player->pos, dir_vector, VIEW_COLOR, img);
}

void	draw_player(t_player *player, t_img_info *img)
{
	t_point	a;
	t_point	b;

	set_values(&a, player->pos.x - PLAYER_W, player->pos.y - PLAYER_W);
	set_values(&b, player->pos.x + PLAYER_W, player->pos.y - PLAYER_W);
	draw_segment(a, b, PLAYER_COLOR, img);
	set_values(&b, player->pos.x - PLAYER_W, player->pos.y + PLAYER_W);
	draw_segment(a, b, PLAYER_COLOR, img);
	set_values(&a, player->pos.x + PLAYER_W, player->pos.y + PLAYER_W);
	draw_segment(a, b, PLAYER_COLOR, img);
	set_values(&b, player->pos.x + PLAYER_W, player->pos.y - PLAYER_W);
	draw_segment(a, b, PLAYER_COLOR, img);
	draw_dir_view(player, img);
}
