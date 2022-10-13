/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:05:12 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 10:23:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

typedef struct s_wall
{
	int			start_x;
	double			start_y;
	double		y_incr;
	t_img_info *texture;
}	t_wall;

/* #define NO	0x3498AD */
/* #define SO	0x5172FF */
/* #define EA	0x1863BB */
/* #define WE	0x55AA2F */

static void	init_wall(t_wall *wall, t_core *core, t_raycast *raycast, int h)
{
	double	fact;

	wall->start_y = 0.0;
	if (raycast->id == 0)
	{
		if (raycast->ray >= SOUTH && raycast->ray <= NORTH)
			wall->texture = &core->EA;
		else
			wall->texture = &core->WE;
		fact = raycast->best_point->y - floor(raycast->best_point->y);
		wall->start_x = (int) round(fact * wall->texture->width);
		wall->y_incr = (double) wall->texture->height / h; 
	}
	else
	{
		if (raycast->ray >= WEST)
			wall->texture = &core->SO;
		else
			wall->texture = &core->NO;
		fact = raycast->best_point->x - floor(raycast->best_point->x);
		wall->start_x = (int) round(fact * wall->texture->width);
		wall->y_incr = (double) wall->texture->height / h; 
	}
}

void	draw_wall(t_core *core, int x, t_raycast *raycast)
{
	t_wall	wall;
	t_point	a;
	t_point	b;
	int		wall_height;

	wall_height = round((1 / raycast->dist) * WIN_HEIGHT / 2);
	init_wall(&wall, core, raycast, wall_height);
	a.x = x;
	b.x = x;
	a.y = 0;
	b.y = round((WIN_HEIGHT / 2.0) - (wall_height / 2.0));
	draw_segment(a, b, core->map->texture->ceiling_rgb, &core->main_img);
	a.y = b.y;
	b.y = round((WIN_HEIGHT / 2.0) + (wall_height / 2.0));
	while (a.y <= b.y)
	{
		char	*dst;
		char	*src;
		t_img_info *img = &core->main_img;
	
		if ((a.y < 0 || a.y > img->height) || (a.x < 0 || a.x > img->width))
		{
			wall.start_y += wall.y_incr;
			a.y++;
			continue ;
		}
		dst = img->addr + (a.y * img->line_length + a.x * (img->bpp / 8));
		src = wall.texture->addr + (((int) round(wall.start_y)) * wall.texture->line_length + wall.start_x * (wall.texture->bpp / 8));
		*(unsigned int *) dst = *(unsigned int *) src;
		wall.start_y += wall.y_incr;
		a.y++;
	}
	b.y = WIN_HEIGHT;
	draw_segment(a, b, core->map->texture->floor_rgb, &core->main_img);
}


/* static void	init_wall(t_wall *wall, t_core *core, t_raycast *raycast, int h) */
/* { */
/* 	(void) core; */
/* 	(void) h; */
/*  */
/* 	wall->start_y = 0; */
/* 	if (raycast->id == 0) */
/* 	{ */
/* 		if (raycast->ray >= SOUTH && raycast->ray <= NORTH) */
/* 			wall->texture = EA; */
/* 		else */
/* 			wall->texture = WE; */
/* 	} */
/* 	else */
/* 	{ */
/* 		if (raycast->ray >= WEST) */
/* 			wall->texture = SO; */
/* 		else */
/* 			wall->texture = NO; */
/* 	} */
/* } */
/*  */
/* void	draw_wall(t_core *core, int x, t_raycast *raycast) */
/* { */
/* 	t_wall	wall; */
/* 	t_point	a; */
/* 	t_point	b; */
/* 	int		wall_height; */
/*  */
/* 	wall_height = round((1 / raycast->dist) * WIN_HEIGHT / 2); */
/* 	init_wall(&wall, core, raycast, wall_height); */
/* 	a.x = x; */
/* 	b.x = x; */
/* 	a.y = 0; */
/* 	b.y = round((WIN_HEIGHT / 2.0) - (wall_height / 2.0)); */
/* 	draw_segment(a, b, core->map->texture->ceiling_rgb, &core->main_img); */
/* 	a.y = b.y; */
/* 	b.y = round((WIN_HEIGHT / 2.0) + (wall_height / 2.0)); */
/* 	while (a.y <= b.y) */
/* 	{ */
/* 		char	*dst; */
/* 		t_img_info *img = &core->main_img; */
/* 	 */
/* 		dst = img->addr + (a.y * img->line_length + a.x * (img->bpp / 8)); */
/* 		*(unsigned int *) dst = wall.texture; */
/* 		wall.start_y = (int) round(wall.start_y + wall.y_incr); */
/* 		a.y++; */
/* 	} */
/* 	b.y = WIN_HEIGHT; */
/* 	draw_segment(a, b, core->map->texture->floor_rgb, &core->main_img); */
/* } */
