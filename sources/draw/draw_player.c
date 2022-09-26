/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:57:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 15:17:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "player.h"
#include "init.h"
#include "math.h"

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
	incr_angle = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		vect_fov.x = pos.x;
		vect_fov.x += (int) round(FOV_SIZE * cos(curr_angle));
		vect_fov.y = pos.y;
		vect_fov.y += (int) round(FOV_SIZE * sin(curr_angle));
		draw_segment(pos, vect_fov, FOV_COLOR, img);
		curr_angle += (incr_angle * RAD);
		i++;
	}
}

void	draw_player(t_point pos, t_player *player, t_img_info *img)
{
	draw_rect_fill(pos, PLAYER_W, PLAYER_COLOR, img);
	draw_intersec_horizontal(pos, player, img);
	draw_dir_view(pos, player, img);
}
