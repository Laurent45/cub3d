/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:36:49 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/12 13:50:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <stddef.h>

int	create_img(t_core *core, t_img_info *img, int width, int height)
{
	if (img->img)
	{
		mlx_destroy_image(core->mlx, img->img);
		img->img = NULL;
		img->addr = NULL;
	}
	img->img = mlx_new_image(core->mlx, width, height);
	if (!img->img)
		return (FAILED);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,\
			&img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(core->mlx, img->img);
		img->img = NULL;
		return (FAILED);
	}
	img->width = width;
	img->height = height;
	return (SUCCESS);
}
