/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:50 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 15:17:33 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <stddef.h>

int	display_minimap(t_core *core)
{
	if (core->mini_map.img)
	{
		mlx_destroy_image(core->mlx, core->mini_map.img);
		core->mini_map.img = NULL;
		core->mini_map.addr = NULL;
		if (create_img(core, &core->main_img, WIN_WIDTH, WIN_HEIGHT) == FAILED)
			return (FAILED);
		raycasting(core);
		mlx_put_image_to_window(core->mlx, core->win, core->main_img.img, 0, 0);
	}
	else
	{
		if (create_img(core, &core->mini_map, W_MINIMAP, H_MINIMAP) == FAILED)
			return (FAILED);
		draw_minimap(core);
		mlx_put_image_to_window(core->mlx, core->win, core->mini_map.img, 0, 0);
	}
	return (SUCCESS);
}
