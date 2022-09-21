/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:41:43 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/21 15:28:51 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

#include "struct.h"

/**
 *
 */
void	draw_segment(t_point a, t_point b, int color, t_img_info *img);

/**
 *
 */
void	put_pixel_img(t_img_info *img, int x, int y, int color);

/**
 *
 */
void	draw_player(t_player *player, t_img_info *img);

/**
 *
 */
void	create_img(t_core *core, t_img_info *img);

#endif
