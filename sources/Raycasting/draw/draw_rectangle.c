/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:04:16 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 16:21:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"

#include <math.h>

void	draw_rect_fill(t_rect *rect, t_img_info *img)
{
	t_point	a;
	t_point	b;
	int	y_end;

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

void	draw_rect(t_point center, int size, int color, t_img_info *img)
{
	t_point	a;
	t_point	b;

	a.x = center.x - size / 2;
	a.y = center.y - size / 2;
	b.x = center.x + size / 2;
	b.y = a.y;
	draw_segment(a, b, color, img);
	b.y = center.y + size / 2;
	draw_segment(a, b, color, img);
	a.x = center.x + size / 2;
	a.y = b.y;
	draw_segment(a, b, color, img);
	b.x = a.x;
	b.y = center.y - size / 2;
}
