/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:17:22 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/28 15:46:44 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"

#include <stdlib.h>

//TODO: check if init failed
void	init_mlx(t_core *core)
{
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	core->main_img.img = NULL;
}

void	clear_mlx(t_core *core)
{
	mlx_destroy_image(core->mlx, core->main_img.img);
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free(core->mlx);
}
