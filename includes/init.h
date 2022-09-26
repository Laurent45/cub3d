/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:18:33 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 13:15:37 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"

# define WIN_WIDTH	720
# define WIN_HEIGHT	720
# define WIN_TITLE	"Cub3d"

# define SIZE_CUBE	60.0
# define EMPTY_CUBE	0xFFFFFF
# define WALL_CUBE	0x009999

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
