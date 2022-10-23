/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:45:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/14 12:21:15 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

#include "Raycasting.h"
#include "mlx.h"

int	main(int argc, char **argv, char **envp)
{
	t_map	*map;
	t_core	core;

	map = parsing(argc, argv, envp);
	if (!map)
		return (1);
	if (init(map, &core) == FAILED)
		return (clear(&core), 1);
	if (create_img(&core, &core.main_img, WIN_WIDTH, WIN_HEIGHT) == FAILED)
		return (clear(&core), 1);
	init_hook(&core);
	raycasting(&core);
	mlx_put_image_to_window(core.mlx, core.win, core.main_img.img, 0, 0);
	mlx_loop(core.mlx);
	return (clear(&core), 0);
}
