/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:04:16 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 20:34:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include <math.h>

void	draw_rect_fill(t_rect *rect, t_img_info *img)
{
	t_point	a;
	t_point	b;
	int		y_end;

	a.x = round(rect->center.x - rect->l_width / 2.0);
	a.y = round(rect->center.y - rect->l_height / 2.0);
	b.x = round(rect->center.x + rect->l_width / 2.0);
	y_end = round(rect->center.y + rect->l_height / 2.0);
	while (a.y <= y_end)
	{
		b.y = a.y;
		draw_segment(a, b, rect->color, img);
		a.y++;
	}
}

void	draw_rect(t_rect *rect, t_img_info *img)
{
	t_point	a;
	t_point	b;

	a.x = round(rect->center.x - rect->l_width / 2.0);
	a.y = round(rect->center.y - rect->l_height / 2.0);
	b.x = round(rect->center.x + rect->l_width / 2.0);
	b.y = a.y;
	draw_segment(a, b, rect->color, img);
	b.x = a.x;
	b.y = a.y + rect->l_height;
	draw_segment(a, b, rect->color, img);
	a.x = b.x + rect->l_width;
	a.y = b.y;
	draw_segment(a, b, rect->color, img);
	b.x = a.x;
	b.y = a.y - rect->l_height;
	draw_segment(a, b, rect->color, img);
}
