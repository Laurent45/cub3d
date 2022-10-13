/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:31:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 07:32:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

#include <stdlib.h>

void	ft_clear_mlx(t_core	*core, t_img_info *img)
{
	mlx_destroy_image(core->mlx, img->img);
	mlx_destroy_window(core->mlx, core->win);
	mlx_destroy_display(core->mlx);
	free(core->mlx);
}
