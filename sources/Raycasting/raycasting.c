/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:56:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 16:31:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>
/* static void	horizontal_intersec(t_map *map, t_player *player, double ray, t_raycast *raycast) */
/* { */
/* 	t_point	a; */
/* 	t_point	incr; */
/*  */
/* 	set_point(&incr, 1, SIZE_CUBE); */
/* 	if (ray >= WEST) */
/* 	{ */
/* 		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE - 1; */
/* 		set_point(&incr, -1, -SIZE_CUBE); */
/* 	} */
/* 	else */
/* 		a.y = ((int) (player->pos.y / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE; */
/* 	a.x = player->pos.x + round((a.y - player->pos.y) / tan(ray * RAD)); */
/* 	if (a.x < 0 || a.x > WIN_WIDTH) */
/* 		return set_point(&raycast->horizontal, -1 , -1); */
/* 	incr.x *= (int) round(SIZE_CUBE / tan(ray * RAD));  */
/* 	set_point(&raycast->horizontal, a.x, a.y); */
/* 	while (!is_wall(a)) */
/* 	{ */
/* 		set_point(&a, a.x + incr.x, a.y + incr.y); */
/* 		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT) */
/* 			return set_point(&raycast->horizontal, -1 , -1); */
/* 		set_point(&raycast->horizontal, a.x, a.y); */
/* 	} */
/* } */

static void	horizontal_intersec(t_map *map, t_player *player, double ray, t_raycast *raycast)
{
	t_pos	a;
	double	incr_x;
	double	incr_y;

	incr_x = 1;
	incr_y = 1;
	if (ray >= WEST)
	{
		a.y = floor(player->pos_y);
		incr_x = -1;
		incr_y = -1;
	}
	else
		a.y = round(player->pos_y);
	a.x = player->pos_x + ((a.y - player->pos_y) / tan(to_rad(ray)));
	if (a.x < 0.0 || a.x > WIN_WIDTH)
		return (set_position(&raycast->horizontal, -1 , -1));
	incr_x *= round(1 / tan(to_rad(ray))); 
	set_position(&raycast->horizontal, a.x, a.y);
	while (!is_wall(map, &a))
	{
		set_position(&a, a.x + incr_x, a.y + incr_y);
		if (a.x < 0.0 || a.x > WIN_WIDTH || a.y < 0.0 || a.y > WIN_HEIGHT)
			return set_position(&raycast->horizontal, -1 , -1);
		set_position(&raycast->horizontal, a.x, a.y);
	}
}

/* static void	vertical_intersec(t_map *map, t_player *player, double ray, t_raycast *raycast) */
/* { */
/* 	t_point	a; */
/* 	t_point	incr; */
/*  */
/* 	set_point(&incr, SIZE_CUBE, 1); */
/* 	if (ray >= NORTH || ray <= SOUTH) */
/* 		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE; */
/* 	else */
/* 	{ */
/* 		a.x = ((int) (player->pos.x / SIZE_CUBE)) * SIZE_CUBE - 1; */
/* 		set_point(&incr, -SIZE_CUBE, -1); */
/* 	} */
/* 	a.y = player->pos.y - round((player->pos.x - a.x) * tan(ray * RAD)); */
/* 	if (a.y < 0 || a.y > WIN_WIDTH) */
/* 		return set_point(&raycast->vertical, -1 , -1); */
/* 	incr.y *= (int) round(tan(ray * RAD) * SIZE_CUBE); */
/* 	set_point(&raycast->vertical, a.x, a.y); */
/* 	while (!is_wall(a)) */
/* 	{ */
/* 		set_point(&a, a.x + incr.x, a.y + incr.y); */
/* 		if (a.x < 0 || a.x > WIN_WIDTH || a.y < 0 || a.y > WIN_HEIGHT) */
/* 			return set_point(&raycast->vertical, -1 , -1); */
/* 		set_point(&raycast->vertical, a.x, a.y); */
/* 	} */
/* } */

void	raycasting(t_map *map, t_core *core)
{
	t_raycast	raycast;
	double	curr_angle;
	double	incr_angle;
	int		i;

	curr_angle = set_angle(core->player.dir - (FOV / 2));
	incr_angle = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		horizontal_intersec(map, core->player, curr_angle, &raycast);
		curr_angle = set_angle(curr_angle + incr_angle);
		i++;
	}

}


/* void	best_intersec(t_raycast *raycast, t_player *player) */
/* { */
/* 	double	dist_h; */
/* 	double	dist_v; */
/*  */
/* 	if (raycast->vertical.x == -1) */
/* 	{ */
/* 		raycast->best_point = &raycast->horizontal; */
/* 		raycast->dist = get_dist(&player->pos, &raycast->horizontal); */
/* 	} */
/* 	else if (raycast->horizontal.x == -1) */
/* 	{ */
/* 		raycast->best_point = &raycast->vertical; */
/* 		raycast->dist = get_dist(&player->pos, &raycast->vertical); */
/* 	} */
/* 	else */
/* 	{ */
/* 		dist_h = get_dist(&player->pos, &raycast->horizontal); */
/* 		dist_v = get_dist(&player->pos, &raycast->vertical); */
/* 		raycast->best_point = &raycast->horizontal; */
/* 		raycast->dist = dist_h; */
/* 		if (dist_h >= dist_v) */
/* 		{ */
/* 			raycast->best_point = &raycast->vertical; */
/* 			raycast->dist = dist_v; */
/* 		} */
/* 	} */
/* } */
/*  */
/* void	wall_slice(int x, t_raycast *raycast, t_img_info *img) */
/* { */
/* 	t_point	a; */
/* 	t_point	b; */
/* 	const int dist_project_plane = 500; */
/* 	int	height_slice = round(SIZE_CUBE / raycast->dist * dist_project_plane); */
/*  */
/* 	a.x = x; */
/* 	b.x = x; */
/* 	a.y = round((WIN_HEIGHT / 2.0) - (height_slice / 2.0)); */
/* 	b.y = round((WIN_HEIGHT / 2.0) + (height_slice / 2.0)); */
/* 	draw_segment(a, b, WALL_CUBE, img); */
/*  */
/*  */
/*  */
/*  */
/* 	int tmp = b.y; */
/* 	b.y = a.y;  */
/* 	a.y = 0; */
/* 	draw_segment(a, b, 0x000000, img); */
/* 	a.y = tmp; */
/* 	b.y = WIN_HEIGHT; */
/* 	draw_segment(a, b, 0x1299FF, img); */
/* } */
