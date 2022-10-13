/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:45:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 07:33:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

#include "Raycasting.h"
#include "mlx.h"

// TODO: Leaks
int	main(int argc, char **argv, char **envp)
{
	t_map	*map;
	t_core	core;

	map = parsing(argc, argv, envp);
	if (!map)
		return (1);
	if (init(map, &core) == FAILED)
		return (free_map(map, 0), 1);
	if (create_img(&core, &core.main_img, WIN_WIDTH, WIN_HEIGHT) == FAILED)
		return (free_map(map, 0), 1);
	init_hook(&core);
 	/* draw_map(&core.main_img, map); */
	draw_player(&core);
	mlx_put_image_to_window(core.mlx, core.win, core.main_img.img, 0, 0);
	mlx_loop(core.mlx);
	free_map(map, 0);
	return (0);
}
