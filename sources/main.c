/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <ldubuche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:45:47 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 12:13:02 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "image.h"
#include "init.h"
#include "player.h"
#include "mlx.h"

#include <stdlib.h>

int	map[12][12] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	clear_mlx(t_core *core)
{
	mlx_destroy_image(core->mlx, core->main_img.img);
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free(core->mlx);
}

int	main()
{
	t_core		core;

	init_mlx(&core);
	init_player(&core.player);
	init_hook(&core);
	main_img(&core);
	
	mlx_loop(core.mlx);
	clear_mlx(&core);
}
