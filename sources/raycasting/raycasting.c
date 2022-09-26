/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 20:54:47 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "player.h"
#include "init.h"
#include "draw.h"
#include <math.h>

void	horizontal_intersec(t_point pos, t_player *player, double current_ray, t_img_info *img)
{
	(void) player;
	t_point	a;

	// Find coordinate of A
	/*
	 * Which block chose according to angle of current ray.
	 * Either the block above the line (-1) or the block below the line (+64)
	 */
	if (current_ray >= WEST && current_ray <= 2 * PI)
		a.y = ((int) floor(pos.y / SIZE_CUBE)) * SIZE_CUBE - 1;
	else
		a.y = ((int) floor(pos.y / SIZE_CUBE)) * SIZE_CUBE + SIZE_CUBE;
	//a.y /= SIZE_CUBE;
	/*
	 * Calculate x coordinate of A. tan (ALPHA) = (p.y - a.y) / (a.x - p.x)
	 * Be carreful wich quadrant you are
	 */
	a.x = round(((pos.y - a.y) / tan(current_ray)) + pos.x);
	//a.x /= SIZE_CUBE;
	draw_segment(a, pos, FOV_COLOR, img);

}
