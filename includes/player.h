/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/29 09:21:38 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "struct.h"

# define SOUTH			90.0
# define NORTH			270.0
# define EST			0.0
# define WEST			180.0

# define PLAYER_X		6	
# define PLAYER_Y		4
# define PLAYER_W		10
# define PLAYER_DIR		NORTH
# define PLAYER_SPEED	0.5
# define PLAYER_COLOR	0x00FF00

# define RAD			0.01745329
# define VIEW_SIZE		30.0
# define VIEW_INCR		2
# define VIEW_COLOR		0x000000


# define FOV			66.0
# define FOV_SIZE		VIEW_SIZE / 2
# define FOV_COLOR		0x999900
# define FOV_COLOR_2	0x66B2FF

/**
 *
 */
void	init_player(t_player *player);

/**
 *
 */
void	draw_player(t_player *player, t_img_info *img);

/**
 *
 */
void	update_view_vector(t_player *player);

/**
 *
 */
void	update_pos(t_player *player);

/**
 *
 */
void	reset_pos(t_player *player);

#endif
