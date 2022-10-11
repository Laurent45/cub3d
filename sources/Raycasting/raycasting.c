/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:56:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 17:32:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

void	horizontal_intersec(t_core *core, double ray, t_raycast *raycast)
{
	t_pos	a;
	t_pos	incr;
	int		dir;

	set_position(&incr, 1, 1);
	dir = SOUTH;
	if (ray >= WEST)
	{
		a.y = floor(core->player.pos.y);
		set_position(&incr, -1, -1);
		dir = NORTH;
	}
	else
		a.y = floor(core->player.pos.y + 1);
	a.x = core->player.pos.x + ((a.y - core->player.pos.y) / tan(to_rad(ray)));
	if (a.x < 0 || a.x > core->map->width)
		return set_position(&raycast->horizontal, 0, 0);
	incr.x *= (1 / tan(to_rad(ray))); 
	while (!is_wall(core->map, &a, dir))
	{
		set_position(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > core->map->width || a.y < 0 || a.y > core->map->height)
			return set_position(&raycast->horizontal, 0, 0);
	}
	set_position(&raycast->horizontal, a.x, a.y);
}

void	vertical_intersec(t_core *core, double ray, t_raycast *raycast)
{
	t_pos	a;
	t_pos	incr;
	int		dir;

	set_position(&incr, 1, 1);
	dir = EAST;
	if (ray >= NORTH || ray <= SOUTH)
		a.x = floor(core->player.pos.x + 1);
	else
	{
		a.x = floor(core->player.pos.x);
		set_position(&incr, -1, -1);
		dir = WEST;
	}
	a.y = core->player.pos.y + ((a.x - core->player.pos.x) * tan(to_rad(ray)));
	if (a.y < 0 || a.y > core->map->height)
		return set_position(&raycast->vertical, 0, 0);
	incr.y *= tan(to_rad(ray)); 
	while (!is_wall(core->map, &a, dir))
	{
		set_position(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > core->map->width || a.y < 0 || a.y > core->map->height)
			return set_position(&raycast->vertical, 0, 0);
	}
	set_position(&raycast->vertical, a.x, a.y);
}

void	raycasting(t_core *core)
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
		horizontal_intersec(core, curr_angle, &raycast);
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
