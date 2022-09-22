/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:18:33 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/22 16:49:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

# define WIN_WIDTH	720
# define WIN_HEIGHT	720
# define WIN_TITLE	"Cub3d"

# define SIZE_CUBE	60
# define EMPTY_CUBE	0xFFFFFF
# define WALL_CUBE	0x009999

# define PLAYER_X		100
# define PLAYER_Y		100
# define PLAYER_W		10
# define PLAYER_SPEED	0.5
# define PLAYER_COLOR	0x00FF00

# define VIEW_SIZE		15
# define VIEW_INCR		0.1745329
# define VIEW_COLOR		0x000000
# define MAX_RADIAN		6.283185
# define R_45			1.570796

# define SUCCESS		0
# define FAILED			1

/**
 *
 */
void	init_mlx(t_core *core);

/**
 *
 */
void	set_values(t_point *point, int x, int y);

/**
 *
 */
void	init_hook(t_core *core);

#endif
