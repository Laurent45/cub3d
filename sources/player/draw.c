/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:00:49 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/06 09:23:44 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "init.h"
#include "raycasting.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

void draw_intersec(t_player *player, t_img_info *img)
{
	int			i;
	double		curr_angle;
	double		incr_angle;
	t_raycast	raycast;
	t_point		vect_fov;

	curr_angle = player->view.angle - (FOV / 2);
	curr_angle = set_angle(curr_angle);
	incr_angle = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		vect_fov.x = player->pos.x;
		vect_fov.x += (int) round(FOV_SIZE * cos(curr_angle * RAD));
		vect_fov.y = player->pos.y;
		vect_fov.y += (int) round(FOV_SIZE * sin(curr_angle * RAD));
		horizontal_intersec(player, curr_angle, &raycast);
		vertical_intersec(player, curr_angle, &raycast);
		/* if (raycast.horizontal.x != -1 && raycast.horizontal.y != -1) */
		/* 	draw_segment(player->pos, raycast.horizontal, FOV_COLOR, img); */
		/* if (raycast.vertical.x != -1 && raycast.vertical.y != -1) */
		/* 	draw_segment(player->pos, raycast.vertical, FOV_COLOR_2, img); */
		best_intersec(&raycast, player);
		/* raycast.dist = round(raycast.dist); */
		/* printf("dist %f\n", raycast.dist); */
		/* // Distortion correction */
		raycast.dist *= cos((curr_angle - player->view.angle) * RAD); 
		wall_slice(i, &raycast, img);
		/* draw_segment(player->pos, *raycast.best_point, FOV_COLOR_2, img); */
		/* draw_segment(player->pos, vect_fov, 0xFFFFFF, img); */
		curr_angle += (incr_angle);
		curr_angle = set_angle(curr_angle);
		i++;
	}
}

void	draw_player(t_player *player, t_img_info *img)
{
	t_point	dir_vector;
	
	draw_rect_fill(player->pos, PLAYER_W, PLAYER_COLOR, img);
	dir_vector.x = player->pos.x + player->view.v_front.x;
	dir_vector.y = player->pos.y + player->view.v_front.y;
	draw_segment(player->pos, dir_vector, VIEW_COLOR, img);
	draw_intersec(player, img);
}
