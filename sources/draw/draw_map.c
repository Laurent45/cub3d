/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:12:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 15:22:07 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "init.h"

extern int map[12][12];

void	draw_map(t_img_info *img)
{
	int		i;
	int		j;
	t_point	a;

	i = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			a.x = (j * SIZE_CUBE) + SIZE_CUBE / 2;
			a.y = (i * SIZE_CUBE) + SIZE_CUBE / 2;
			if (map[i][j] == 0)
				draw_rectangle(a, SIZE_CUBE, EMPTY_CUBE, img);
			else
				draw_rectangle(a, SIZE_CUBE, WALL_CUBE, img);
			j++;
		}
		i++;
	}
}
