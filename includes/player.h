/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 15:15:58 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "struct.h"

# define PLAYER_X		100
# define PLAYER_Y		100
# define PLAYER_W		10
# define PLAYER_SPEED	0.5
# define PLAYER_COLOR	0x00FF00

# define PI				3.141593
# define RAD			0.01745329
# define VIEW_SIZE		30.0
# define VIEW_INCR		0.1745329
# define VIEW_COLOR		0x000000

# define SOUTH			PI / 2.0
# define NORTH			3.0 * PI / 2.0
# define EST			0
# define WEST			PI

# define FOV			120.0
# define FOV_SIZE		VIEW_SIZE / 2
# define FOV_COLOR		0x999900

/**
 *
 */
void	init_player(t_player *player);

/**
 *
 */
void	update_view(t_player *player);

/**
 *
 */
void	update_pos(t_player *player);

#endif
