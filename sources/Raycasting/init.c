/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:54:00 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 20:58:43 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "Raycasting.h"

#include <stdio.h>
#include <stddef.h>

static void	init_player(t_map *map, t_player *player)
{
	player->pos.x = map->posX + 0.5;
	player->pos.y = map->posY + 0.5;
	player->pos_tmp.x = player->pos.x;
	player->pos_tmp.y = player->pos.y;
	if (map->direction == NORTH)
		player->dir = 270.0;
	if (map->direction == SOUTH)
		player->dir = 90.0;
	if (map->direction == EAST)
		player->dir = 0.0;
	if (map->direction == WEST)
		player->dir = 180.0;
	player->f_front = 0.0;
	player->f_side = 0.0;
}

int	init(t_map *map, t_core *core)
{
	core->mlx = mlx_init();
	if (core->mlx == NULL)
	{
		printf("Init mlx failed\n");
		return (FAILED);
	}
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (core->win == NULL)
	{
		printf("Create window failed\n");
		return (FAILED);
	}
	core->main_img.img = NULL;
	init_player(map, &core->player);
	core->map = map;
	return (SUCCESS);
}

int	init_main_img(t_core *core, int width, int height)
{
	if (core->main_img.img)
	{
		mlx_destroy_image(core->mlx, core->main_img.img);
		core->main_img.img = NULL;
		core->main_img.addr = NULL;
	}
	core->main_img.img = mlx_new_image(core->mlx, width, height);
	if (core->main_img.img == NULL)
		return (FAILED);
	core->main_img.addr = mlx_get_data_addr(core->main_img.img,\
			&core->main_img.bpp, &core->main_img.line_length,\
			&core->main_img.endian);
	if (core->main_img.addr == NULL)
	{
		mlx_destroy_image(core->mlx, core->main_img.img);
		return (FAILED);
	}
	core->main_img.width = width;
	core->main_img.height = height;
	return (SUCCESS);
}

void	init_hook(t_core *core)
{
	mlx_hook(core->win, 17, 1L << 17, close_red, core);
	mlx_hook(core->win, 2, 1L << 0, key_press, core);
}
