/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/06 17:20:56 by lfrederi         ###   ########.fr       */
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
void	horizontal_intersec(t_player *player, double ray, t_raycast *raycast)
{
	t_point	a;
	t_point	incr;

	set_values(&incr, 1, SIZE_CUBE);
	if (ray >= WEST)
	{
		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE - 1;
		set_values(&incr, -1, -SIZE_CUBE);
	}
	else
		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
	a.x = player->pos.x + round((a.y - player->pos.y) / tan(ray * RAD));
	if (a.x < 0 || a.x > WIN_WIDTH)
		return set_values(&raycast->horizontal, -1 , -1);
	incr.x *= (int) round(SIZE_CUBE / tan(ray * RAD)); 
	set_values(&raycast->horizontal, a.x, a.y);
	while (!is_wall(a))
	{
		set_values(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT)
			return set_values(&raycast->horizontal, -1 , -1);
		set_values(&raycast->horizontal, a.x, a.y);
	}
}

void	vertical_intersec(t_player *player, double ray, t_raycast *raycast)
{
	t_point	a;
	t_point	incr;

	set_values(&incr, SIZE_CUBE, 1);
	if (ray >= NORTH || ray <= SOUTH)
		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
	else
	{
		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE - 1;
		set_values(&incr, -SIZE_CUBE, -1);
	}
	a.y = player->pos.y - round((player->pos.x - a.x) * tan(ray * RAD));
	if (a.y < 0 || a.y > WIN_WIDTH)
		return set_values(&raycast->vertical, -1 , -1);
	incr.y *= (int) round(tan(ray * RAD) * SIZE_CUBE);
	set_values(&raycast->vertical, a.x, a.y);
	while (!is_wall(a))
	{
		set_values(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT)
			return set_values(&raycast->vertical, -1 , -1);
		set_values(&raycast->vertical, a.x, a.y);
	}
}

void	best_intersec(t_raycast *raycast, t_player *player)
{
	double	dist_h;
	double	dist_v;

	if (raycast->vertical.x == -1)
	{
		raycast->best_point = &raycast->horizontal;
		raycast->dist = get_dist(&player->pos, &raycast->horizontal);
	}
	else if (raycast->horizontal.x == -1)
	{
		raycast->best_point = &raycast->vertical;
		raycast->dist = get_dist(&player->pos, &raycast->vertical);
	}
	else
	{
		dist_h = get_dist(&player->pos, &raycast->horizontal);
		dist_v = get_dist(&player->pos, &raycast->vertical);
		raycast->best_point = &raycast->horizontal;
		raycast->dist = dist_h;
		if (dist_h >= dist_v)
		{
			raycast->best_point = &raycast->vertical;
			raycast->dist = dist_v;
		}
	}
}

void	wall_slice(int x, t_raycast *raycast, t_img_info *img)
{
	t_point	a;
	t_point	b;
	const int dist_project_plane = 500;
	int	height_slice = round(SIZE_CUBE / raycast->dist * dist_project_plane);

	a.x = x;
	b.x = x;
	a.y = round((WIN_HEIGHT / 2.0) - (height_slice / 2.0));
	b.y = round((WIN_HEIGHT / 2.0) + (height_slice / 2.0));
	draw_segment(a, b, WALL_CUBE, img);




	int tmp = b.y;
	b.y = a.y; 
	a.y = 0;
	draw_segment(a, b, 0x000000, img);
	a.y = tmp;
	b.y = WIN_HEIGHT;
	draw_segment(a, b, 0x1299FF, img);
}
