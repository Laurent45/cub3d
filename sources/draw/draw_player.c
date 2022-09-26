/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:57:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 20:54:52 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "player.h"
#include "init.h"
#include "utils.h"
#include "raycasting.h"
#include <math.h>

static void	draw_dir_view(t_point pos, t_player *player, t_img_info *img)
{
	t_point	dir_vector;

	dir_vector.x = pos.x + player->view.v_front.x;
	dir_vector.y = pos.y + player->view.v_front.y;
	draw_segment(pos, dir_vector, VIEW_COLOR, img);
}

static void draw_intersec_horizontal(t_point pos, t_player *player, t_img_info *img)
{
	int	i;
	double	curr_angle;
	double	incr_angle;
	t_point	vect_fov;

	curr_angle = player->view.angle - ((FOV / 2) * RAD);
	curr_angle = set_angle(curr_angle);
	incr_angle = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		vect_fov.x = pos.x;
		vect_fov.x += (int) round(FOV_SIZE * cos(curr_angle));
		vect_fov.y = pos.y;
		vect_fov.y += (int) round(FOV_SIZE * sin(curr_angle));
		//horizontal_intersec(pos, player, curr_angle, img);
		draw_segment(pos, vect_fov, 0x000000, img);
		curr_angle += (incr_angle * RAD);
		curr_angle = set_angle(curr_angle);
		i++;
	}
}

void	draw_player(t_player *player, t_img_info *img)
{
	t_point	curr_pos;

	curr_pos.x = player->pos.x;
	curr_pos.x += (player->view.v_front.x * player->f_front);
	curr_pos.x += (player->view.v_side.x * player->f_side);
	curr_pos.y = player->pos.y;
	curr_pos.y += (player->view.v_front.y * player->f_front);
	curr_pos.y += (player->view.v_side.y * player->f_side);
	draw_rect_fill(curr_pos, PLAYER_W, PLAYER_COLOR, img);
	draw_intersec_horizontal(curr_pos, player, img);
	draw_dir_view(curr_pos, player, img);
}
