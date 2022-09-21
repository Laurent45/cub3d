/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:43:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 09:21:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "init.h"

void	put_pixel_img(t_img_info *img, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x >= WIN_WIDTH) || (y < 0 || y >= WIN_HEIGHT))
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
