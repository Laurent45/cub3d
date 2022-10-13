/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:58:27 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 20:19:03 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double	set_angle(double angle)
{
	if (angle < 0.0)
		return (360.0 + angle);
	if (angle >= 360.0)
		return (angle - 360.0);
	return (angle);
}

double	to_rad(double angle)
{
	return ((angle * M_PI) / 180.0);
}

double	distance(t_pos *a, t_pos *b)
{
	return (sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2)));
}

void	pixel_point(t_point *a, t_pos *pos, t_core *core, t_img_info *img)
{
	a->x = round(pos->x * ((double) img->width / core->map->width));
	a->y = round(pos->y * ((double) img->height / core->map->height));
}
