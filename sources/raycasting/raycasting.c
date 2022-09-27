/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 16:11:39 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "player.h"
#include "init.h"
#include "utils.h"
#include <math.h>

void	horizontal_intersec(t_player *player, double curr_ray, t_img_info *img)
{
	double	tmp;
	t_point	a;
	int		y_incr;
	int		x_incr;

	// Find coordinate of A
	/*
	 * Which block chose according to angle of current ray.
	 * Either the block above the line (-1) or the block below the line (+64)
	 */
	if (curr_ray >= WEST)
	{
		a.y = ((int) floor(player->pos.y / SIZE_CUBE)) * SIZE_CUBE - 1;
		y_incr = -SIZE_CUBE;
	}
	else
	{
		a.y = ((int) floor(player->pos.y / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
		y_incr = SIZE_CUBE;
	}
	//a.y /= SIZE_CUBE;
	/*
	 * Calculate x coordinate of A. tan (ALPHA) = (p.y - a.y) / (a.x - p.x)
	 */
	tmp = (a.y - player->pos.y) / tan(curr_ray);
	a.x = player->pos.x + round(tmp);
	//a.x /= SIZE_CUBE;
	x_incr = round(SIZE_CUBE / tan(curr_ray)); 
	if (a.x < 0 || a.x > WIN_WIDTH)
		return ;
	draw_segment(a, player->pos, FOV_COLOR, img);
	while (!is_wall(a))
	{
		a.x += x_incr;
		a.y += y_incr;
		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT)
			return ;
		draw_segment(a, player->pos, FOV_COLOR, img);
	}
}

void	vertical_intersec(t_player *player, double curr_ray, t_img_info *img)
{
	double	tmp;
	t_point	a;

	// Find coordinate of A
	/*
	 * Which block chose according to angle of current ray.
	 * Either the block above the line (-1) or the block below the line (+64)
	 */
	if (curr_ray >= NORTH || curr_ray <= SOUTH)
		a.x = ((int) floor(player->pos.x / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
	else
		a.x = ((int) floor(player->pos.x / SIZE_CUBE)) * SIZE_CUBE - 1;
	//a.x /= SIZE_CUBE;
	/*
	 * Calculate y coordinate of A. tan (ALPHA) = (p.y - a.y) / (a.x - p.x)
	 */
	tmp = (player->pos.x - a.x) * tan(curr_ray);
	a.y = player->pos.y - round(tmp);
	//a.y /= SIZE_CUBE;
	if (a.y >= 0 && a.y <= WIN_WIDTH)
		draw_segment(a, player->pos, FOV_COLOR_2, img);
}
