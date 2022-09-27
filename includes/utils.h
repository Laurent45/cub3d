/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:09:36 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/27 15:32:06 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include <stddef.h>

/**
 *
 */
void	set_values(t_point *point, int x, int y);

/**
 *
 */
int		abs(int x);

/**
 *
 */
double	set_angle(double angle);

/**
 *
 */
void	draw_segment(t_point a, t_point b, int color, t_img_info *img);

/**
 *
 */
void	draw_rect(t_point center, size_t size, int color, t_img_info *img);

/**
 *
 */
void	draw_rect_fill(t_point center, size_t size, int color, t_img_info *img);

/**
 *
 */
void	draw_map(t_img_info *img);

#endif
