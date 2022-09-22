/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:57:39 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 18:47:59 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "init.h"

static void	draw_dir_view(t_point pos, t_player *player, t_img_info *img)
{
	t_point	dir_vector;

	dir_vector.x = pos.x + player->view.v_front.x;
	dir_vector.y = pos.y + player->view.v_front.y;
	draw_segment(pos, dir_vector, VIEW_COLOR, img);
}

void	draw_player(t_point pos, t_player *player, t_img_info *img)
{
	draw_rectangle(pos, PLAYER_W, PLAYER_COLOR, img);
	draw_dir_view(pos, player, img);
}
