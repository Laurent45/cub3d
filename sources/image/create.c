/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:25:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 15:33:23 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "player.h"
#include "utils.h"
#include "init.h"
#include "mlx.h"

void	main_img(t_core *core)
{
	t_img_info	*img;

	img = &core->main_img;
	if (img->img)
		mlx_destroy_image(core->mlx, img->img);
	img->img = mlx_new_image(core->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	draw_map(img);	
	draw_player(&core->player, img);	
	mlx_put_image_to_window(core->mlx, core->win, img->img, 0, 0);
}
