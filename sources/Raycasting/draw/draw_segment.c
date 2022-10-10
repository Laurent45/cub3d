/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:58:44 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 14:01:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"

static void	init_increment(t_point a, t_point b, int increment[2])
{
	increment[0] = 1;
	increment[1] = 1;
	if (a.x > b.x)
		increment[0] = -1;
	if (a.x == b.x)
		increment[0] = 0;
	if (a.y > b.y)
		increment[1] = -1;
	if (a.y == b.y)
		increment[1] = 0;
}

static void	draw_dx(t_seg seg, int color, t_img_info *img, int incr[2])
{
	int	e;
	int	dx;
	int	dy;
	int	x_curr;
	int	y_curr;

	e = abs(seg.b.x - seg.a.x);
	dx = 2 * e;
	dy = 2 * abs(seg.b.y - seg.a.y);
	x_curr = seg.a.x;
	y_curr = seg.a.y;
	while (x_curr != seg.b.x)
	{
		put_pixel_img(img, x_curr, y_curr, color);
		x_curr += incr[0];
		e -= dy;
		if (e < 0)
		{
			y_curr += incr[1];
			e += dx;
		}
	}
	put_pixel_img(img, seg.b.x, seg.b.y, color);
}

static void	draw_dy(t_seg seg, int color, t_img_info *img, int incr[2])
{
	int	e;
	int	dx;
	int	dy;
	int	x_curr;
	int	y_curr;

	e = abs(seg.b.y - seg.a.y);
	dy = 2 * e;
	dx = 2 * abs(seg.b.x - seg.a.x);
	x_curr = seg.a.x;
	y_curr = seg.a.y;
	while (y_curr != seg.b.y)
	{
		put_pixel_img(img, x_curr, y_curr, color); 
		y_curr += incr[1];
		e -= dx;
		if (e < 0)
		{
			x_curr += incr[0];
			e += dy;
		}
	}
	put_pixel_img(img, seg.b.x, seg.b.y, color) ;
}

void	draw_segment(t_point a, t_point b, int color, t_img_info *img)
{
	int		incr[2];
	t_seg	seg;

	if ((a.x == b.x) && (a.y == b.y))
		put_pixel_img(img, a.x, a.y, color);
	else
	{
		seg.a = a;
		seg.b = b;
		init_increment(a, b, incr);
		if (abs(b.x - a.x) >= abs(b.y - a.y))
			draw_dx(seg, color, img, incr);
		else if (abs(b.x - a.x) < abs(b.y - a.y))
			draw_dy(seg, color, img, incr);
	}
}
