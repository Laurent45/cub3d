/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:33 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 18:21:48 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"
#include "image.h"
#include "mlx.h"
#include <stdio.h>

int	close_red(void *hook)
{
	return (mlx_loop_end(((t_hook *) hook)->core->mlx));
}

int	key_press(int keycode, void *hook)
{
	t_hook	*vars;

	vars = (t_hook *) hook;
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S\
		|| keycode == KEY_D)
	{
		if (move_player(&vars->core->player, keycode) == SUCCESS)
			create_img(vars->core, vars->img);
	}
	if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
	{
		move_dir_view(&vars->core->player, keycode);
		create_img(vars->core, vars->img);
	}
	if (keycode == ESC)
		press_esc(vars);

	return (0);
}
