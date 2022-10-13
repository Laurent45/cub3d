/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:31:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 14:16:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <stdlib.h>

void	clear(t_core *core)
{
	if (core->main_img.img)
		mlx_destroy_image(core->mlx, core->main_img.img);
	if (core->mini_map.img)
		mlx_destroy_image(core->mlx, core->mini_map.img);
	if (core->NO.img)
		mlx_destroy_image(core->mlx, core->NO.img);
	if (core->SO.img)
		mlx_destroy_image(core->mlx, core->SO.img);
	if (core->EA.img)
		mlx_destroy_image(core->mlx, core->EA.img);
	if (core->WE.img)
		mlx_destroy_image(core->mlx, core->WE.img);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free(core->mlx);
	free_map(core->map, 0);
}
