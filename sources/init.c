/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:17:22 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 17:39:50 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "hook.h"
#include "mlx.h"

//TODO: check if init failed
void	init_mlx(t_core *core)
{
	t_player	*player;

	player = &core->player;
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	player->pos.x = PLAYER_X;
	player->pos.y = PLAYER_X;
	player->dir_view.x = VIEW_SIZE;
	player->dir_view.y = 0;
	player->angle_view = 0.0;
}

void	set_values(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void	init_hook(t_hook *hook, t_core *core, t_img_info *img)
{
	hook->core = core;
	hook->img = img;
	mlx_hook(hook->core->win, 17, 1L << 17, close_red, hook);
	mlx_hook(hook->core->win, 2, 1L << 0, key_press, hook);
}
