/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:45:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/10 16:43:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

#include "Raycasting.h"
#include "mlx.h"
#include "mlx_int.h"

int	main(int argc, char **argv, char **envp)
{
	t_map	*map;
	t_core	core;

	map = parsing(argc, argv, envp);
	if (!map)
		return (1);
	if (init(map, &core) == 0)
		return (free_map(map, 0), 1);


	core.main_img.img = mlx_new_image(core.mlx, WIN_WIDTH, WIN_HEIGHT);
	core.main_img.addr = mlx_get_data_addr(core.main_img.img, &core.main_img.bpp, &core.main_img.line_length, &core.main_img.endian);
	draw_map(&core.main_img, map);
	draw_player(&core.main_img, &core.player, map);
	mlx_put_image_to_window(core.mlx, core.win, core.main_img.img, 0, 0);
	mlx_loop(core.mlx);

	free_map(map, 0);
	return (0);
}
