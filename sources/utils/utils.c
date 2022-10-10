/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:08:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/06 09:39:24 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"
#include "player.h"

#include <math.h>

extern int map[12][12];

int	is_wall(t_point a)
{
	int x;
	int	y;

	x = (int) a.x / SIZE_CUBE;
	y = (int) a.y / SIZE_CUBE;
	if (map[y][x])
		return (1);
			return (0);
}

void	set_values(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	set_angle(double angle)
{
	if (angle < 0.0)
		return (360 + angle);
	if (angle >= 360)
		return (angle - 360);
	return (angle);
}

double	get_dist(t_point *a, t_point *b)
{
	return (sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)));
}
