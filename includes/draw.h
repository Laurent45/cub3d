/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:36:18 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/26 14:11:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "struct.h"
#include <stddef.h>

/**
 *
 */
void	draw_segment(t_point a, t_point b, int color, t_img_info *img);

/**
 *
 */
void	draw_map(t_img_info *img);

/**
 *
 */
void	draw_player(t_point pos, t_player *player, t_img_info *img);

/**
 *
 */
void	draw_rect(t_point center, size_t size, int color, t_img_info *img);

/**
 *
 */
void	draw_rect_fill(t_point center, size_t size, int color, t_img_info *img);

#endif
