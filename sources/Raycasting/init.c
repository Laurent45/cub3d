/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:54:00 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/12 13:54:12 by lfrederi         ###   ########.fr       */
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
