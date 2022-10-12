/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:56:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/12 14:38:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"
#include <math.h>

/*static void	horizontal_intersec(t_core *core, double ray, t_raycast *raycast)
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
	if (a.x < 0.0 || a.x > core->map->width)
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

static void	vertical_intersec(t_core *core, double ray, t_raycast *raycast)
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
	if (a.y < 0.0 || a.y > core->map->height)
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

static void	best_intersec(t_raycast *raycast, t_player *player)
{
	double	dist_h;
	double	dist_v;

	if (raycast->horizontal.x == 0.0 || raycast->vertical.x == 0.0)
	{
		if (raycast->horizontal.x == 0.0)
			raycast->best_point = &raycast->vertical;
		else
			raycast->best_point = &raycast->horizontal;
		raycast->dist = distance(&player->pos, raycast->best_point);
	}
	else
	{
		dist_h = distance(&player->pos, &raycast->horizontal);
		dist_v = distance(&player->pos, &raycast->vertical);
		raycast->best_point = &raycast->horizontal;
		raycast->dist = dist_h;
		if (dist_h >= dist_v)
		{
			raycast->best_point = &raycast->vertical;
			raycast->dist = dist_v;
		}
	}
}

static void	wall_slice(int x, t_raycast *raycast, t_img_info *img)
{
	t_point	a;
	t_point	b;
	int	height_slice = round((1 / raycast->dist) * WIN_HEIGHT);

	a.x = x;
	b.x = x;
	a.y = round((WIN_HEIGHT / 2.0) - (height_slice / 2.0));
	b.y = round((WIN_HEIGHT / 2.0) + (height_slice / 2.0));
	draw_segment(a, b, 0x32AA02, img);
	int tmp = b.y;
	b.y = a.y; 
	a.y = 0;
	draw_segment(a, b, 0x000000, img);
	a.y = tmp;
	b.y = WIN_HEIGHT;
	draw_segment(a, b, 0x1299FF, img);
}*/

void	raycasting(t_core *core, t_rect *rect)
{
	(void) rect;
	/* t_raycast	raycast; */
	/* double		curr_angle; */
	/* double		incr_angle; */
	/* int			i; */

	t_img_info t;
	t.img = mlx_xpm_file_to_image(core->mlx, "./wall_WE.xpm", &t.width, &t.height);
	/* curr_angle = set_angle(core->player.dir - (FOV / 2)); */
	/* incr_angle = FOV / WIN_WIDTH; */
	/* i = 0; */
	/* while (i < WIN_WIDTH) */
	/* { */
	/* 	raycast.ray = curr_angle; */
	/* 	raycast.id = 0; */
	/* 	horizontal_intersec(core, curr_angle, &raycast); */
	/* 	vertical_intersec(core, curr_angle, &raycast); */
	/* 	best_intersec(&raycast, &core->player); */
	/* 	if (raycast.best_point == &raycast.horizontal) */
	/* 		raycast.id = 1; */
	/* 	raycast.dist = raycast.dist * cos(to_rad(core->player.dir - curr_angle)); */
	/* 	t_point b; */
	/* 	pixel_point(&b, raycast.best_point, core); */
	/* 	draw_segment(rect->center, b, 0x34B2A8, &core->main_img); */
	/* 	wall_slice(i, &raycast, &core->main_img); */
	/* 	curr_angle = set_angle(curr_angle + incr_angle); */
	/* 	i++; */
	/* } */
	mlx_put_image_to_window(core->mlx, core->win, t.img, 0, 0);
}
