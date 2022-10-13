/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:54:00 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 16:46:20 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "Raycasting.h"

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

static int	init_texture(t_core *core, t_img_info *texture, char *filename)
{
	void		*mlx;

	mlx = core->mlx;
	texture->img = mlx_xpm_file_to_image(mlx, filename, &texture->width, \
			&texture->height);
	if (!texture->img)
		return (FAILED);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (FAILED);
	return (SUCCESS);
}

static void	set_null(t_core *core)
{
	core->mlx = NULL;
	core->win = NULL;
	core->img_no.img = NULL;
	core->img_no.addr = NULL;
	core->img_so.img = NULL;
	core->img_so.addr = NULL;
	core->img_ea.img = NULL;
	core->img_ea.addr = NULL;
	core->img_we.img = NULL;
	core->img_we.addr = NULL;
	core->main_img.img = NULL;
	core->main_img.addr = NULL;
	core->mini_map.img = NULL;
	core->mini_map.addr = NULL;
}

int	init(t_map *map, t_core *core)
{
	set_null(core);
	core->mlx = mlx_init();
	if (!core->mlx)
		return (put_error("Init mlx failed", FAILED));
	core->win = mlx_new_window(core->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (core->win == NULL)
		return (put_error("Create window failed", FAILED));
	if (init_texture(core, &core->img_no, map->texture->no_texture) == FAILED)
		return (put_error("Texture NO failed", FAILED));
	if (init_texture(core, &core->img_so, map->texture->so_texture) == FAILED)
		return (put_error("Texture SO failed", FAILED));
	if (init_texture(core, &core->img_ea, map->texture->ea_texture) == FAILED)
		return (put_error("Texture EA failed", FAILED));
	if (init_texture(core, &core->img_we, map->texture->we_texture) == FAILED)
		return (put_error("Texture WE failed", FAILED));
	init_player(map, &core->player);
	core->map = map;
	return (SUCCESS);
}
