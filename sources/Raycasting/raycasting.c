/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:56:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 20:16:21 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"
#include <math.h>

static void	h_wall(t_player *player, t_map *map, double ray, t_raycast *raycast)
{
	t_pos	a;
	t_pos	incr;
	int		dir;

	set_position(&incr, 1, 1);
	dir = SOUTH;
	if (ray >= WEST)
	{
		a.y = floor(player->pos.y);
		set_position(&incr, -1, -1);
		dir = NORTH;
	}
	else
		a.y = floor(player->pos.y + 1);
	a.x = player->pos.x + ((a.y - player->pos.y) / tan(to_rad(ray)));
	if (a.x < 0.0 || a.x > map->width)
		return (set_position(&raycast->horizontal, 0, 0));
	incr.x *= (1 / tan(to_rad(ray)));
	while (!is_wall(map, &a, dir))
	{
		set_position(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > map->width || a.y < 0 || a.y > map->height)
			return (set_position(&raycast->horizontal, 0, 0));
	}
	set_position(&raycast->horizontal, a.x, a.y);
}

static void	v_wall(t_player *player, t_map *map, double ray, t_raycast *raycast)
{
	t_pos	a;
	t_pos	incr;
	int		dir;

	set_position(&incr, 1, 1);
	dir = EAST;
	if (ray >= NORTH || ray <= SOUTH)
		a.x = floor(player->pos.x + 1);
	else
	{
		a.x = floor(player->pos.x);
		set_position(&incr, -1, -1);
		dir = WEST;
	}
	a.y = player->pos.y + ((a.x - player->pos.x) * tan(to_rad(ray)));
	if (a.y < 0.0 || a.y > map->height)
		return (set_position(&raycast->vertical, 0, 0));
	incr.y *= tan(to_rad(ray));
	while (!is_wall(map, &a, dir))
	{
		set_position(&a, a.x + incr.x, a.y + incr.y);
		if (a.x < 0 || a.x > map->width || a.y < 0 || a.y > map->height)
			return (set_position(&raycast->vertical, 0, 0));
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

void	raycasting(t_core *core)
{
	t_raycast	raycast;
	double		ray;
	double		incr_angle;
	int			i;

	ray = set_angle(core->player.dir - (FOV / 2));
	incr_angle = FOV / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		raycast.ray = ray;
		raycast.id = 0;
		h_wall(&core->player, core->map, ray, &raycast);
		v_wall(&core->player, core->map, ray, &raycast);
		best_intersec(&raycast, &core->player);
		if (raycast.best_point == &raycast.horizontal)
			raycast.id = 1;
		raycast.dist = raycast.dist * cos(to_rad(core->player.dir - ray));
		draw_wall(core, i, &raycast);
		ray = set_angle(ray + incr_angle);
		i++;
	}
}
