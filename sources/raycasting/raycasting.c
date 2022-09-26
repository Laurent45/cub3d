/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:52:38 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 14:02:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "init.h"
#include <math.h>

void	horizontal_intersec(t_player *player, double current_ray)
{
	t_point	a;
	t_point *pos_player;

	pos_player = &player->pos;
	// Find coordinate of A
	/*
	 * Which block chose according to angle of current ray.
	 * Either the block above the line (-1) or the block below the line (+64)
	 */
	if (current_ray >= EST && current_ray <= WEST)
		a.y = (int) round(pos_player->y / SIZE_CUBE) * SIZE_CUBE - 1;
	else
		a.y = (int) round(pos_player->y / SIZE_CUBE) * SIZE_CUBE + SIZE_CUBE;
	a.y /= SIZE_CUBE;
	/*
	 * Calculate x coordinate of A. tan (ALPHA) = (p.y - a.y) / (a.x - p.x)
	 */
	a.x = round(((pos_player->y - a.y) / tan(current_ray)) + pos_player->x);
	a.x /= SIZE_CUBE;


	


}
