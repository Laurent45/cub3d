/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:17:22 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 12:09:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"
#include "event.h"

#include <stddef.h>

//TODO: check if init failed
void	init_mlx(t_core *core)
{
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	core->main_img.img = NULL;
}


void	init_hook(t_core *core)
{
	mlx_hook(core->win, 17, 1L << 17, close_red, core);
	mlx_hook(core->win, 2, 1L << 0, key_press, core);
}
