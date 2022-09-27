/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:21:10 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 15:29:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_rect_fill(t_point center, size_t size, int color, t_img_info *img)
{
	t_point	a;
	t_point	b;
	int	y_end;

	a.x = center.x - size / 2;
	a.y = center.y - size / 2;
	b.x = center.x + size / 2;
	y_end = center.y + size / 2;
	while (a.y <= y_end)
	{
		b.y = a.y;
		draw_segment(a, b, color, img);
		a.y++;
	}
}

void	draw_rect(t_point center, size_t size, int color, t_img_info *img)
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
