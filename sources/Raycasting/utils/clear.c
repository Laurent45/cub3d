/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:31:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 16:49:30 by lfrederi         ###   ########.fr       */
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
	if (core->img_no.img)
		mlx_destroy_image(core->mlx, core->img_no.img);
	if (core->img_so.img)
		mlx_destroy_image(core->mlx, core->img_so.img);
	if (core->img_ea.img)
		mlx_destroy_image(core->mlx, core->img_ea.img);
	if (core->img_we.img)
		mlx_destroy_image(core->mlx, core->img_we.img);
	if (core->mlx && core->win)
		mlx_destroy_window(core->mlx, core->win);
	if (core->mlx)
		mlx_destroy_display(core->mlx);
	free(core->mlx);
	free_map(core->map, 0);
}
