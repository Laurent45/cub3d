/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:23 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/28 16:31:26 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "player.h"
#include "image.h"
#include "utils.h"

void	move_dir_view(t_core *core, int keycode)
{
	t_player	*player;

	player = &core->player;
	if (player->f_front != 0.0 || player->f_side != 0.0)
		reset_pos(player);
	if (keycode == ARROW_LEFT)
		player->view.angle -= VIEW_INCR;
	if (keycode == ARROW_RIGHT)
		player->view.angle += VIEW_INCR;
	player->view.angle = set_angle(player->view.angle);
	update_view_vector(player);
	main_img(core);
}
