/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:15:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/10/11 20:30:56 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Raycasting.h"
#include "mlx.h"

int	close_red(void *core)
{
	return (mlx_loop_end(((t_core *) core)->mlx));
}

int	key_press(int keycode, void *core)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S\
		|| keycode == KEY_D)
		move_player((t_core *) core, keycode);
	if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		move_dir((t_core *) core, keycode);
	if (keycode == ESC)
		press_esc((t_core *) core);

	return (0);
}
