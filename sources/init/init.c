/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:17:22 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:25:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"
#include "event.h"

#include <stddef.h>

static void	init_player(t_player *player)
{
	player->pos.x = PLAYER_X;
	player->pos.y = PLAYER_Y;
	player->view.angle = 0;
	player->view.v_front.x = VIEW_SIZE;
	player->view.v_front.y = 0;
	player->view.v_side.x = 0;
	player->view.v_side.y = -VIEW_SIZE;
	player->f_front = 0.0;
	player->f_side = 0.0;
}

//TODO: check if init failed
void	init_mlx(t_core *core)
{
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	core->main_img.img = NULL;
	init_player(&core->player);
}

void	set_values(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	init_hook(t_core *core)
{
	mlx_hook(core->win, 17, 1L << 17, close_red, core);
	mlx_hook(core->win, 2, 1L << 0, key_press, core);
}
