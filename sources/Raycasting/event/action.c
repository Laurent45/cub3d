/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:15:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/13 15:16:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

int	close_red(void *core)
{
	return (mlx_loop_end(((t_core *) core)->mlx));
}

int	key_press(int key, void *core)
{
	if (key == ESC)
		return (press_esc((t_core *) core), 0);
	if ((key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D) \
			&& (move_player((t_core *) core, key) == FAILED))
		return (mlx_loop_end(((t_core *) core)->mlx));
	if ((key == ARROW_RIGHT || key == ARROW_LEFT) \
		&& (move_dir((t_core *) core, key) == FAILED))
		return (mlx_loop_end(((t_core *) core)->mlx));
	if (key == KEY_M && display_minimap((t_core *) core) == FAILED)
		return (mlx_loop_end(((t_core *) core)->mlx));
	return (0);
}
