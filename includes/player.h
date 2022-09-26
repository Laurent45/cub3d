/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:13:13 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 11:57:16 by lfrederi         ###   ########.fr       */
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
# define VIEW_SIZE		15.0
# define VIEW_INCR		0.1745329
# define VIEW_COLOR		0x000000

# define SOUTH			PI / 2.0
# define NORTH			3.0 * PI / 2.0
# define EST			0
# define WEST			PI

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
