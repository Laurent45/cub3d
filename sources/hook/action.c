/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:15:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 19:44:18 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"
#include "image.h"
#include "mlx.h"

#include <math.h>
#include <stdio.h>

int	move_player(t_player *player, int keycode)
{
	t_point	tmp;

	if (keycode == KEY_W)
	{
		player->pos.x += player->dir_view.x * PLAYER_SPEED;
		player->pos.y += player->dir_view.y * PLAYER_SPEED;
	}
	if (keycode == KEY_S)
	{
		player->pos.x += -player->dir_view.x * PLAYER_SPEED;
		player->pos.y += -player->dir_view.y * PLAYER_SPEED;
	}
	if (keycode == KEY_A)
	{
		tmp.x = (int) ceil(VIEW_SIZE * cos(player->angle_view - 1.570796));
		tmp.y = (int) ceil(VIEW_SIZE * sin(player->angle_view - 1.570796));
		player->pos.x += tmp.x * PLAYER_SPEED;
		player->pos.y += tmp.y * PLAYER_SPEED;
	}
	if (keycode == KEY_D)
	{
		tmp.x = (int) ceil(VIEW_SIZE * cos(player->angle_view + 1.570796));
		tmp.y = (int) ceil(VIEW_SIZE * sin(player->angle_view + 1.570796));
		player->pos.x += tmp.x * PLAYER_SPEED;
		player->pos.y += tmp.y * PLAYER_SPEED;
	}
	return (SUCCESS);
}

void	move_dir_view(t_player *player, int keycode)
{
	if (keycode == ARROW_LEFT)
		player->angle_view -= VIEW_INCR;
	if (keycode == ARROW_RIGHT)
		player->angle_view += VIEW_INCR;
	if (player->angle_view > MAX_RADIAN)
		player->angle_view -= MAX_RADIAN;
	if (player->angle_view <= 0.0)
		player->angle_view = MAX_RADIAN + player->angle_view;
	player->dir_view.x = (int) ceil(VIEW_SIZE * cos(player->angle_view));
	player->dir_view.y = (int) ceil(VIEW_SIZE * sin(player->angle_view));
}

void	press_esc(t_hook *hook)
{
	mlx_loop_end(hook->core->mlx);
}
