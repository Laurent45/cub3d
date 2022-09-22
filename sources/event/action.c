/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:15:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:30:05 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "mlx.h"

int	close_red(void *vars)
{
	return (mlx_loop_end(((t_core *) vars)->mlx));
}

int	key_press(int keycode, void *vars)
{
	t_core	*core;

	core = (t_core *) vars;
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S\
		|| keycode == KEY_D)
		move_player(core, keycode);
	if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		move_dir_view(core, keycode);
	if (keycode == ESC)
		press_esc(core);

	return (0);
}
