/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:41:17 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/28 09:13:27 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/*
 *
 */
void	horizontal_intersec(t_player *player, double current_ray, t_raycast *raycast);

/*
 *
 */
void	vertical_intersec(t_player *player, double current_ray, t_raycast *raycast);

/**
 *
 */
void	best_intersec(t_raycast *raycast, t_player *player);

/**
 *
 */
void	wall_slice(int x, t_raycast *raycast, t_img_info *img);

#endif
