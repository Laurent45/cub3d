/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 19:53:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "player.h"
#include "init.h"
#include "utils.h"
#include <math.h>

	// Find coordinate of A
	/*
	 * Which block chose according to angle of current ray.
	 * Either the block above the line (-1) or the block below the line (+64)
	 * Calculate x coordinate of A. tan (ALPHA) = (p.y - a.y) / (a.x - p.x)
	 */
void	horizontal_intersec(t_player *player, double curr_ray, t_img_info *img)
{
	double	tmp;
	t_point	a;
	int		y_incr;
	int		x_incr;
	int		up;

	if (curr_ray >= WEST)
	{
		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE - 1;
		y_incr = -SIZE_CUBE;
		up = -1;
	}
	else
	{
		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
		y_incr = SIZE_CUBE;
		up = 1;
	}
	tmp = (a.y - player->pos.y) / tan(curr_ray);
	a.x = player->pos.x + round(tmp);
	x_incr = (int) round(SIZE_CUBE / tan(curr_ray) * up); 
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
	int		y_incr;
	int		x_incr;
	int		up;

	if (curr_ray >= NORTH || curr_ray <= SOUTH)
	{
		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
		x_incr = SIZE_CUBE;
		up = 1;
	}
	else
	{
		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE - 1;
		x_incr = -SIZE_CUBE;
		up = -1;
	}
	tmp = (player->pos.x - a.x) * tan(curr_ray);
	a.y = player->pos.y - round(tmp);
	if (a.y < 0 || a.y > WIN_WIDTH)
		return ;
	y_incr = (int) round(tan(curr_ray) * SIZE_CUBE * up);
	draw_segment(a, player->pos, FOV_COLOR_2, img);
	while (!is_wall(a))
	{
		a.x += x_incr;
		a.y += y_incr;
		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT)
			return ;
		draw_segment(a, player->pos, FOV_COLOR_2, img);
	}
}
