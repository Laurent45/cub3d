/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:08:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 16:04:11 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"
#include "player.h"

#include <stdio.h>

extern int map[12][12];

int	is_wall(t_point a)
{
	int x;
	int	y;

	x = (int) a.x / SIZE_CUBE;
	y = (int) a.y / SIZE_CUBE;
	printf("x, y => %d %d\n", x, y);
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
		return ((2 * PI) + angle);
	if (angle >= 2 * PI)
		return (angle - (2 * PI));
	return (angle);
}
