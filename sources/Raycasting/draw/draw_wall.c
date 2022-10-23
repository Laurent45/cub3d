/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:05:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/14 11:23:25 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

static void	init_wall(t_wall *wall, t_core *core, t_raycast *raycast, int h)
{
	double	fact;

	wall->y = 0.0;
	if (raycast->id == 0)
	{
		if (raycast->ray >= SOUTH && raycast->ray <= NORTH)
			wall->texture = &core->img_ea;
		else
			wall->texture = &core->img_we;
		fact = raycast->best_point->y - floor(raycast->best_point->y);
		wall->start_x = (int) round(fact * wall->texture->width);
		wall->y_incr = (double) wall->texture->height / h;
	}
	else
	{
		if (raycast->ray >= WEST)
			wall->texture = &core->img_so;
		else
			wall->texture = &core->img_no;
		fact = raycast->best_point->x - floor(raycast->best_point->x);
		wall->start_x = (int) round(fact * wall->texture->width);
		wall->y_incr = (double) wall->texture->height / h;
	}
}

static void	set_pixel_wall(t_wall *wall, t_core *core, t_point *a, t_point *b)
{
	char		*dst;
	char		*src;
	t_img_info	*img;

	img = &core->main_img;
	while (a->y != b->y)
	{
		if ((a->y >= 0 && a->y <= img->height) \
			&& (a->x >= 0 && a->x <= img->width))
		{
			dst = img->addr + (a->y * img->line_length + a->x * (img->bpp / 8));
			src = wall->texture->addr + (((int) round(wall->y)) \
					* wall->texture->line_length + wall->start_x \
					* (wall->texture->bpp / 8));
			*(unsigned int *) dst = *(unsigned int *) src;
		}
		wall->y += wall->y_incr;
		a->y++;
	}
}

void	draw_wall(t_core *core, int x, t_raycast *raycast)
{
	t_wall	wall;
	t_point	a;
	t_point	b;
	int		wall_height;

	if (raycast->dist <= 0.0)
		wall_height = WIN_HEIGHT;
	else
		wall_height = round((1 / raycast->dist) * WIN_HEIGHT);
	init_wall(&wall, core, raycast, wall_height);
	set_point(&a, x, 0);
	set_point(&b, x, round((WIN_HEIGHT / 2.0) - (wall_height / 2.0)));
	draw_segment(a, b, core->map->texture->ceiling_rgb, &core->main_img);
	a.y = b.y;
	b.y = round((WIN_HEIGHT / 2.0) + (wall_height / 2.0));
	set_pixel_wall(&wall, core, &a, &b);
	b.y = WIN_HEIGHT;
	draw_segment(a, b, core->map->texture->floor_rgb, &core->main_img);
}
